#include "dlt_logger.h"

#include <array>
#include <chrono>
#include <iostream>

void DltLogger::init(const std::string& app_id, const std::string& app_description)
{
    std::cout << "[Logger] DltLogger::init!" << std::endl;

    DLT_REGISTER_APP(app_id.c_str(), app_description.c_str());
    DLT_REGISTER_CONTEXT(ctx_main, "MAIN", "Main Log Context");

    running_.store(true, std::memory_order_relaxed);
    worker_thread_ = std::jthread(&DltLogger::process_queue, this);
}

void DltLogger::stop()
{
    if (running_.load(std::memory_order_acquire))
    {
        while (!message_queue_.size_approx() == 0)
        {
            std::this_thread::sleep_for(std::chrono::milliseconds(10));  // Give it the time for worker to complete
        }

        running_.store(false, std::memory_order_release);

        if (worker_thread_.joinable())
        {
            worker_thread_.request_stop();
            worker_thread_.join();
        };

        DLT_UNREGISTER_CONTEXT(ctx_main);
        DLT_UNREGISTER_APP();
    }
}

void DltLogger::log(DltLogLevelType level, std::string message)
{
    message_queue_.enqueue({level, std::move(message)});
}

void DltLogger::process_queue(std::stop_token st)
{
    constexpr size_t bulk_size = 32;
    std::array<LogMessage, bulk_size> message_chunk;

    while (!st.stop_requested())
    {
        size_t dequeued_count = message_queue_.try_dequeue_bulk(message_chunk.begin(), bulk_size);

        if (dequeued_count > 0)
        {
            for (size_t i{0}; i < dequeued_count; i++)
            {
                const auto& item = message_chunk[i];
                DLT_LOG(ctx_main, item.level, DLT_STRING(item.message.c_str()));
            }
        }
        else
        {
            std::this_thread::sleep_for(std::chrono::milliseconds(1));
        }
    }
}
