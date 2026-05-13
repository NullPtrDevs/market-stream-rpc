#pragma once

#include <concurrentqueue.h>
#include <dlt/dlt.h>
#include <yaml-cpp/yaml.h>

#include <atomic>
#include <stop_token>
#include <string>
#include <thread>
#include <vector>

namespace common::logger
{

struct LogMessage
{
    DltLogLevelType level_;
    std::string message_;
};

class DltLogger
{
public:
    static auto instance() -> DltLogger&
    {
        static DltLogger instance;
        return instance;
    }

    DltLogger(const DltLogger&) = delete;
    auto operator=(const DltLogger&) -> DltLogger& = delete;
    DltLogger(const DltLogger&&) = delete;
    auto operator=(const DltLogger&&) -> DltLogger& = delete;

    void init(const std::string& app_id, const std::string& app_description);
    void stop();
    void log(DltLogLevelType level, std::string message);

private:
    DltLogger();
    ~DltLogger()
    {
        stop();
    }

    void process_queue(const std::stop_token& stop_token);

    moodycamel::ConcurrentQueue<LogMessage> message_queue_;

    DLT_DECLARE_CONTEXT(ctx_main_);
    std::vector<DltContext> registered_contexts_;
    std::jthread worker_thread_;
    std::atomic<bool> running_;
};

inline void log_info(std::string message)
{
    DltLogger::instance().log(DLT_LOG_INFO, std::move(message));
}

inline void log_error(std::string message)
{
    DltLogger::instance().log(DLT_LOG_ERROR, std::move(message));
}

inline void log_debug(std::string message)
{
    DltLogger::instance().log(DLT_LOG_DEBUG, std::move(message));
}

inline void log_warn(std::string message)
{
    DltLogger::instance().log(DLT_LOG_WARN, std::move(message));
}

inline void log_fatal(std::string message)
{
    DltLogger::instance().log(DLT_LOG_FATAL, std::move(message));
}

}  // namespace common::logger