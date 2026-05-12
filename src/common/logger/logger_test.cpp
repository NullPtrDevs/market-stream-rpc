#include <cstddef>
#include <iostream>
#include <stop_token>
#include <thread>
#include <vector>

#include "common/logger/dlt_logger.h"

auto main() -> int
{
    using namespace common::logger;
    DltLogger::instance().init("TEST", "Test Application");

    std::vector<std::jthread> workers;
    size_t threads = std::thread::hardware_concurrency();

    workers.reserve(threads);
    for (int i = 0; i < threads; i++)
    {
        workers.emplace_back(
            [i](const std::stop_token& token)
            {
                while (!token.stop_requested())
                {
                    log_info("Message from thread " + std::to_string(i));
                    const auto thread_sleep = 200;
                    std::this_thread::sleep_for(std::chrono::milliseconds(thread_sleep));
                }
            });
    }

    std::this_thread::sleep_for(std::chrono::seconds(2));

    std::cin.get();
    workers.clear();
    DltLogger::instance().stop();
    return 0;
}