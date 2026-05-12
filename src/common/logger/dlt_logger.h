#pragma once

#include <concurrentqueue.h>
#include <dlt/dlt.h>
#include <yaml-cpp/yaml.h>

#include <atomic>
#include <stop_token>
#include <string>
#include <thread>
#include <vector>

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

    DLT_DECLARE_CONTEXT(ctx_main);
    std::vector<DltContext> registered_contexts_;
    std::jthread worker_thread_;
    std::atomic<bool> running_;
};

#define LOG_INFO(msg) DltLogger::instance().log(DLT_LOG_INFO, msg);
#define LOG_ERROR(msg) DltLogger::instance().log(DLT_LOG_ERROR, msg);
#define LOG_DEBUG(msg) DltLogger::instance().log(DLT_LOG_DEBUG, msg);
#define LOG_WARN(msg) DltLogger::instance().log(DLT_LOG_WARN, msg);
#define LOG_FATAL(msg) DltLogger::instance().log(DLT_LOG_FATAL, msg);