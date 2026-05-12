#include "dlt_logger.h"
#include "DltConfig.h"


#include <array>
#include <chrono>
#include <span>

const size_t QUEUE_SIZE = 65536;
DltLogger::DltLogger() : ctx_main{}, running_{false}, message_queue_(QUEUE_SIZE) {};

void DltLogger::init(const std::string& app_id, const std::string& app_description)
{
    DLT_REGISTER_APP(app_id.c_str(), app_description.c_str());
    DLT_REGISTER_CONTEXT(ctx_main, "MAIN", "Main Log Context");

    DltConfig config = DltConfig::from_yaml("config/config.yaml");

    for(const auto& context : config.contexts)
    {
        DLT_DECLARE_CONTEXT(ctx);
        std::copy_n(context.id.begin(), std::min(context.id.size(), size_t{4}), ctx.contextID);
        (void)dlt_register_context(&ctx, context.id.c_str(), context.description.c_str());
    }

    running_.store(true, std::memory_order_relaxed);
    worker_thread_ = std::jthread(&DltLogger::process_queue, this);
}

void DltLogger::stop()
{
    if (running_.load(std::memory_order_acquire))
    {
        while (message_queue_.size_approx() != 0)
        {
            const int WAITING_MSC = 10;
            std::this_thread::sleep_for(std::chrono::milliseconds(WAITING_MSC));  // Give it the time for worker to complete
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
    message_queue_.try_enqueue({.level = level, .message = std::move(message)});
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
            for (const auto& item : std::span(message_chunk).subspan(0, dequeued_count))
            {
                DLT_LOG(ctx_main, item.level, DLT_STRING(item.message.c_str()));
            }
        }
        else
        {
            std::this_thread::sleep_for(std::chrono::milliseconds(1));
        }
    }
}