#pragma once

#include <concurrentqueue.h>
#include <dlt/dlt.h>
#include <yaml-cpp/yaml.h>

#include <atomic>
#include <stop_token>
#include <string>
#include <thread>

struct LogMessage
{
    DltLogLevelType level;
    std::string message;
};

class DltLogger
{
public:
    static DltLogger& instance()
    {
        static DltLogger instance;
        return instance;
    }

    void init(const std::string& app_id, const std::string& app_description);
    void stop();
    void log(DltLogLevelType level, std::string message);

private:
    DltLogger(const DltLogger&) = delete;
    DltLogger& operator=(const DltLogger&) = delete;
    DltLogger(const DltLogger&&) = delete;
    DltLogger& operator=(const DltLogger&&) = delete;

    DLT_DECLARE_CONTEXT(ctx_main);
    DltLogger() : running_{false} {};
    ~DltLogger()
    {
        stop();
    }

    void process_queue(std::stop_token st);

private:
    moodycamel::ConcurrentQueue<LogMessage> message_queue_;

    std::jthread worker_thread_;
    std::atomic<bool> running_;
};

#define LOG_INFO(msg) DltLogger::instance.log(DLT_LOG_INFO, msg);
#define LOG_ERROR(msg) DltLogger::instance.log(DLT_LOG_ERROR, msg);
#define LOG_DEBUG(msg) DltLogger::instance.log(DLT_LOG_DEBUG, msg);
#define LOG_WARN(msg) DltLogger::instance.log(DLT_LOG_WARN, msg);
#define LOG_FATAL(msg) DltLogger::instance.log(DLT_LOG_FATAL, msg);