#include <gtest/gtest.h>

#include <format>
#include <thread>
#include <vector>

#include "spsc_lock_free_queue.h"

using namespace spsc_queue;

// 1) What it does: Performs basic sequential push and pop operations.
// 2) What it verifies: Functional correctness of push, pop, and empty methods in a single-threaded environment.
// 3) Expectation: Elements are retrieved in the same order they were added (FIFO); empty() returns correct state.
TEST(LockFreeQueueTest, BasicOperations)
{
    LockFreeQueueSPSC<int32_t, 16> queue;

    EXPECT_TRUE(queue.empty());
    EXPECT_TRUE(queue.push(1));
    EXPECT_TRUE(queue.push(2));
    EXPECT_FALSE(queue.empty());

    int32_t val1{0};
    const auto res1 = queue.pop(val1);
    ASSERT_TRUE(res1);
    EXPECT_EQ(val1, 1);

    int32_t val2{0};
    const auto res2 = queue.pop(val2);
    ASSERT_TRUE(res2);
    EXPECT_EQ(val2, 2);

    EXPECT_TRUE(queue.empty());
}

// 1) What it does: Runs concurrent producer and consumer loops with 100,000 elements.
// 2) What it verifies: Thread safety and data integrity under continuous contention.
// 3) Expectation: The total sum of consumed values equals the sum of produced values; no data is lost.
TEST(LockFreeQueueTest, ProducerConsumerThreaded)
{
    const int32_t count = 100000;
    LockFreeQueueSPSC<int32_t, 1024> queue;
    std::atomic<int64_t> sum_consumed{0};
    int64_t expected_sum{0};

    std::jthread consumer(
        [&]() -> void
        {
            int32_t consumed = 0;
            int32_t ret_val{0};
            while (consumed < count)
            {
                const auto res = queue.pop(ret_val);
                if (res)
                {
                    sum_consumed += ret_val;
                    consumed++;
                }
            }
        });

    for (int32_t i = 1; i <= count; ++i)
    {
        while (!queue.push(i))
        {
        }
        expected_sum += i;
    }

    consumer.join();

    EXPECT_EQ(sum_consumed.load(), expected_sum);
}

// 1) What it does: Checks a fresh queue instance.
// 2) What it verifies: Correct initialization.
// 3) Expectation: empty() must return true for a new queue.
TEST(LockFreeQueueTest, EmptyQueue)
{
    LockFreeQueueSPSC<int32_t, 16> queue;
    ASSERT_TRUE(queue.empty());
}

// 1) What it does: Pushes and then pops a single element.
// 2) What it verifies: Basic data transfer through the queue.
// 3) Expectation: The popped value exactly matches the pushed value.
TEST(LockFreeQueueTest, PushAndPop)
{
    LockFreeQueueSPSC<int32_t, 16> queue;
    constexpr int32_t item{42};
    ASSERT_TRUE(queue.push(item));
    int32_t popped_item{0};
    ASSERT_TRUE(queue.pop(popped_item));
    ASSERT_EQ(popped_item, item);
}

// 1) What it does: Pushes several elements and then pops them all.
// 2) What it verifies: FIFO (First-In-First-Out) ordering.
// 3) Expectation: Values are retrieved in the same order they were pushed.
TEST(LockFreeQueueTest, PushMultipleAndPopMultiple)
{
    LockFreeQueueSPSC<int32_t, 16> queue;
    for (int32_t i = 0; i < 5; ++i)
    {
        int32_t item = i;
        ASSERT_TRUE(queue.push(item));
    }
    for (int32_t i = 0; i < 5; ++i)
    {
        int32_t popped_item{0};
        ASSERT_TRUE(queue.pop(popped_item));
        ASSERT_EQ(popped_item, i);
    }
}

// 1) What it does: Fills the queue until it is full.
// 2) What it verifies: Behavior when capacity is exceeded.
// 3) Expectation: push() returns false when the queue is full.
TEST(LockFreeQueueTest, QueueFull)
{
    // Queue can store only 15 elements if size is 16
    LockFreeQueueSPSC<int32_t, 16> queue;
    for (int32_t i = 0; i < 15; ++i)
    {
        int32_t item = i;
        ASSERT_TRUE(queue.push(item));
    }
    int32_t item = 15;
    ASSERT_FALSE(queue.push(item));
}

// 1) What it does: Tries to pop an element from an empty queue.
// 2) What it verifies: Safe handling of pop operations on empty state.
// 3) Expectation: pop() returns false.
TEST(LockFreeQueueTest, QueueEmpty)
{
    LockFreeQueueSPSC<int32_t, 16> queue;
    int32_t item{0};
    ASSERT_FALSE(queue.pop(item));
}

// 1) What it does: Spawns separate threads for simultaneous production and consumption.
// 2) What it verifies: Basic thread interaction using busy-wait loops.
// 3) Expectation: All items are transferred; no deadlocks or race conditions.
TEST(LockFreeQueueTest, MultiThreadedPushAndPop)
{
    LockFreeQueueSPSC<int32_t, 16> queue;
    constexpr int32_t iterations_count{100};
    std::thread producer(
        [&queue, iterations_count]()
        {
            for (int32_t i = 0; i < iterations_count; ++i)
            {
                int32_t item = i;
                while (!queue.push(item))
                {
                    // busy wait
                }
            }
        });
    std::thread consumer(
        [&queue, iterations_count]()
        {
            for (int32_t i = 0; i < iterations_count; ++i)
            {
                int32_t item{0};
                while (!queue.pop(item))
                {
                    // busy wait
                }
                ASSERT_GE(item, 0);
                ASSERT_LT(item, 100);
            }
        });
    producer.join();
    consumer.join();
}

// 1) What it does: Instantiates a queue with a specific power-of-two capacity.
// 2) What it verifies: Internal index wrapping logic (often using bitwise AND).
// 3) Expectation: All operations work correctly within the allocated ring buffer boundaries.
TEST(LockFreeQueueTest, PowerOfTwoCapacity)
{
    LockFreeQueueSPSC<int32_t, 512> queue;
    for (int i = 0; i < 511; ++i)
    {
        ASSERT_TRUE(queue.push(i));
    }
    ASSERT_FALSE(queue.push(512));
}

// 1) What it does: Simulates a producer-consumer workload for 5 seconds with timing delays.
// 2) What it verifies: Stability and data consistency over a sustained period of concurrent use.
// 3) Expectation: Total counts and sums match between producer and consumer after completion.
TEST(LockFreeQueueTest, SimulateProducerToConsumer)
{
    LockFreeQueueSPSC<int32_t, 2048> queue;
    constexpr int32_t batch_size = 500;

    std::atomic<bool> done{false};
    std::atomic<int64_t> producer_sum{0};
    std::atomic<int64_t> producer_count{0};
    std::atomic<int64_t> consumer_sum{0};
    std::atomic<int64_t> consumer_count{0};

    // simulate producer
    std::thread producer(
        [&queue, &done, &producer_sum, &producer_count]()
        {
            int32_t item{0};
            while (!done.load(std::memory_order_relaxed))
            {
                if (queue.push(item))
                {
                    producer_sum.fetch_add(item, std::memory_order_relaxed);
                    producer_count.fetch_add(1, std::memory_order_relaxed);
                    item++;
                }
                else
                {
                    std::this_thread::sleep_for(std::chrono::microseconds(1));
                }
            }
        });
    // simulate consumer
    std::thread consumer(
        [&queue, &done, &consumer_sum, &consumer_count, batch_size]()
        {
            int32_t item{0};
            while (!done.load(std::memory_order_relaxed) || !queue.empty())
            {
                if (queue.pop(item))
                {
                    consumer_sum.fetch_add(item, std::memory_order_relaxed);
                    consumer_count.fetch_add(1, std::memory_order_relaxed);
                    if (item >= batch_size)
                    {
                        // simulate send here
                        std::this_thread::sleep_for(std::chrono::microseconds(1));
                    }
                }
                else
                {
                    std::this_thread::yield();
                }
            }
        });
    std::this_thread::sleep_for(std::chrono::seconds(5));
    done.store(true, std::memory_order_relaxed);

    producer.join();
    consumer.join();

    EXPECT_EQ(producer_sum.load(), consumer_sum.load());
    EXPECT_EQ(producer_count.load(), consumer_count.load());
}

// 1) What it does: Simulates production with a consumer that pops elements in bursts (up to 500 at once).
// 2) What it verifies: System reliability during rapid, bursty draining of the queue.
// 3) Expectation: Consistency of sums and counts is maintained despite irregular consumption patterns.
TEST(LockFreeQueueTest, SimulateProducerToConsumerSendLast500FromQueue)
{
    LockFreeQueueSPSC<int32_t, 2048> queue;
    constexpr int32_t batch_size = 500;

    std::atomic<bool> producer_done{false};
    std::atomic<bool> consumer_done{false};
    std::atomic<int64_t> producer_sum{0};
    std::atomic<int64_t> producer_count{0};
    std::atomic<int64_t> consumer_sum{0};
    std::atomic<int64_t> consumer_count{0};

    // simulate producer
    std::thread producer(
        [&queue, &producer_done, &producer_sum, &producer_count]()
        {
            int32_t item{0};
            while (!producer_done.load(std::memory_order_acquire))
            {
                if (queue.push(item))
                {
                    producer_sum.fetch_add(item, std::memory_order_release);
                    producer_count.fetch_add(1, std::memory_order_release);
                    item++;
                }
                else
                {
                    std::this_thread::sleep_for(std::chrono::microseconds(1));
                }
            }
        });
    // simulate consumer
    std::thread consumer(
        [&queue, &consumer_done, &consumer_sum, &consumer_count, batch_size]()
        {
            int32_t item{0};
            auto consume_action = [&consumer_sum, &consumer_count, &item]()
            {
                consumer_sum.fetch_add(item, std::memory_order_release);
                consumer_count.fetch_add(1, std::memory_order_release);
            };
            while (!consumer_done.load(std::memory_order_acquire))
            {
                if (queue.pop(item))
                {
                    consume_action();
                    uint8_t count{0u};
                    while (count++ < 500u && queue.pop(item))
                    {
                        // simulate send here
                        consume_action();
                    }
                }
                else
                {
                    std::this_thread::yield();
                }
            }

            while (queue.pop(item))
            {
                consume_action();
            }
        });
    std::this_thread::sleep_for(std::chrono::seconds(5));
    producer_done.store(true, std::memory_order_release);
    producer.join();
    consumer_done.store(true, std::memory_order_release);
    consumer.join();

    EXPECT_EQ(producer_sum.load(), consumer_sum.load());
    EXPECT_EQ(producer_count.load(), consumer_count.load());
}