#include "dlt_logger.h"

#include <algorithm>
#include <array>
#include <chrono>
#include <cstddef>
#include <iterator>
#include <span>

#include "DltConfig.h"

const size_t QUEUE_SIZE = 65536;
DltLogger::DltLogger() : message_queue_(QUEUE_SIZE), ctx_main{}, running_{false} {};

void DltLogger::init(const std::string& app_id, const std::string& app_description)
{
    DLT_REGISTER_APP(app_id.c_str(), app_description.c_str());
    DLT_REGISTER_CONTEXT(ctx_main, "MAIN", "Main Log Context");

    DltConfig config = DltConfig::from_yaml("config/config.yaml");

    for (const auto& context : config.contexts_)
    {
        DltContext dlt_context{};
        const auto context_id_length = static_cast<std::ptrdiff_t>(std::min(context.id_.size(), sizeof(dlt_context.contextID)));
        std::ranges::copy_n(context.id_.begin(), context_id_length, std::begin(dlt_context.contextID));
        (void)dlt_register_context(&dlt_context, context.id_.c_str(), context.description_.c_str());
        registered_contexts_.push_back(dlt_context);
    }

    running_.store(true, std::memory_order_relaxed);
    worker_thread_ = std::jthread(&DltLogger::process_queue, this);
}

void DltLogger::stop()
{
    if (running_.load(std::memory_order_acquire))
    {
        while (message_queue_.size_approx() != 0)
            const int waiting_msc = 10;
            std::this_thread::sleep_for(std::chrono::milliseconds(waiting_msc));  // Give it the time for worker to complete
            std::this_thread::sleep_for(std::chrono::milliseconds(waiting_msc));  // Give it the time for worker to complete
        }

        running_.store(false, std::memory_order_release);

        if (worker_thread_.joinable())
        {
            worker_thread_.request_stop();
            worker_thread_.join();
        };

        for (auto& context : registered_contexts_)
        {
            DLT_UNREGISTER_CONTEXT(context);
        }
        registered_contexts_.clear();

        DLT_UNREGISTER_CONTEXT(ctx_main);
        DLT_UNREGISTER_APP();
    }
}

void DltLogger::log(DltLogLevelType level, std::string message)
{
    message_queue_.try_enqueue({.level_ = level, .message_ = std::move(message)});
}

void DltLogger::process_queue(const std::stop_token& stop_token)
{
    constexpr size_t bulk_size = 32;
    std::array<LogMessage, bulk_size> message_chunk;

    while (!stop_token.stop_requested())
    {
        size_t dequeued_count = message_queue_.try_dequeue_bulk(message_chunk.begin(), bulk_size);

        if (dequeued_count > 0)
        {
            for (const auto& item : std::span(message_chunk).subspan(0, dequeued_count))
            {
                DLT_LOG(ctx_main, item.level_, DLT_STRING(item.message_.c_str()));
            }
        }
        else
        {
            std::this_thread::sleep_for(std::chrono::milliseconds(1));
        }
    }
}