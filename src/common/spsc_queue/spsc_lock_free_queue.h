#pragma once

#include <array>
#include <atomic>
#include <optional>

/**
 * @brief A lock-free, fixed-size queue for Single Producer / Single Consumer (SPSC) scenarios.
 *
 * This class uses atomic operations with strict memory ordering and cache-line
 * alignment to prevent false sharing and ensure high throughput.
 * IMPORTANT! Do not use this queue for multiplay producers and consumers.
 *
 * @tparam T The type of elements stored in the queue.
 * @tparam Capacity The maximum number of elements. Must be a power of two.
 */

namespace spsc_queue
{
constexpr int32_t ALIGN_VALUE{64};
constexpr int32_t DEFAULT_QUEUE_CAPACITY{2048};

template <std::size_t N>
concept PowerOfTwo = ((N > 0) && (N & (N - 1)) == 0);

template <typename T, size_t Capacity = DEFAULT_QUEUE_CAPACITY>
    requires PowerOfTwo<Capacity>
class LockFreeQueueSPSC
{
public:
    LockFreeQueueSPSC() = default;  // NOLINT (cppcoreguidelines-pro-type-member-init)

    // Non-copyable and non-movable for thread-safety and architectural integrity
    LockFreeQueueSPSC(const LockFreeQueueSPSC&) = delete;
    auto operator=(const LockFreeQueueSPSC&) -> LockFreeQueueSPSC& = delete;
    LockFreeQueueSPSC(LockFreeQueueSPSC&&) = delete;
    auto operator=(LockFreeQueueSPSC&&) -> LockFreeQueueSPSC& = delete;

    ~LockFreeQueueSPSC() = default;

    /**
     * @brief Attempts to push an item into the queue.
     *
     * This method is thread-safe only when called by a single producer thread.
     *
     * @param item The element to be added (passed by reference, moved internally).
     * @return true If the item was successfully added.
     * @return false If the queue is full.
     */
    auto push(const T& item) -> bool
    {
        const size_t current_head = head_.load(std::memory_order_relaxed);  // NOLINT (cppcoreguidelines-init-variables)

        // queue is full
        if (((current_head + 1) & MASK) == tail_.load(std::memory_order_acquire))
        {
            return false;  // NOLINT(readability-simplify-boolean-expr)
        }

        // We need to avoid bounds check because of performance reason.
        // We can guarantee that current_head will always be correct.
        buffer_[current_head] = std::move(item);  // NOLINT (cppcoreguidelines-pro-bounds-avoid-unchecked-container-access)
        head_.store(((current_head + 1) & MASK), std::memory_order_release);
        return true;
    }

    /**
     * @brief Attempts to pop an item from the queue.
     *
     * This method is thread-safe only when called by a single consumer thread.
     * Uses move assignment to transfer the value out of the buffer.
     *
     * @param out_val Reference to a variable where the popped value will be stored.
     * @return true If an item was successfully retrieved.
     * @return false If the queue is empty.
     */
    auto pop(T& out_val) -> bool
    {
        const size_t current_tail = tail_.load(std::memory_order_relaxed);  // NOLINT(cppcoreguidelines-init-variables)

        // queue is empty
        if (current_tail == head_.load(std::memory_order_acquire))
        {
            return false;
        }
        // We need to avoid bounds check because of performance reason.
        // We can guarantee that current_tail will always be correct.
        out_val = std::move(buffer_[current_tail]);  // NOLINT (cppcoreguidelines-pro-bounds-avoid-unchecked-container-access)
        tail_.store(((current_tail + 1) & MASK), std::memory_order_release);
        return true;
    }

    /**
     * @brief Checks if the queue is currently empty.
     *
     * @note The result is a snapshot and might change immediately in a multithreaded context.
     * @return true If the queue contains no elements.
     * @return false If the queue contains at least one element.
     */
    [[nodiscard]] auto empty() const -> bool
    {
        return head_.load(std::memory_order_acquire) == tail_.load(std::memory_order_acquire);
    }

private:
    static constexpr size_t MASK = Capacity - 1;  ///< Bitmask for fast modulo operations.

    std::array<T, Capacity> buffer_;  ///< Internal storage for queue elements.

    /**
     * @brief Atomic head index where the producer inserts new items.
     * Aligned to prevent false sharing with the tail index.
     */
    alignas(ALIGN_VALUE) std::atomic<size_t> head_{0};
    /**
     * @brief Atomic tail index where the consumer retrieves items.
     * Aligned to prevent false sharing with the head index.
     */
    alignas(ALIGN_VALUE) std::atomic<size_t> tail_{0};
};

}  // namespace spsc_queue
