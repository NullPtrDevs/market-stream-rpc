#include <benchmark/benchmark.h>

#include <chrono>
#include <string>
#include <thread>

#include "common/logger/dlt_logger.h"
#include "common/spsc_queue/spsc_lock_free_queue.h"

struct LogFixture
{
    LogFixture()
    {
        DltLogger::instance().init("BENCH", "Benchmark App");
    }

    LogFixture(const LogFixture&) = delete;
    auto operator=(const LogFixture&) -> LogFixture& = delete;
    LogFixture(LogFixture&&) = delete;
    auto operator=(LogFixture&&) -> LogFixture& = delete;

    ~LogFixture()
    {
        constexpr auto stop_wait_duration = std::chrono::milliseconds(500);
        std::this_thread::sleep_for(stop_wait_duration);

        DltLogger::instance().stop();
    }
};

namespace
{
const LogFixture GLOBAL_FIX;
}
static void bm_dlt_logger_push(benchmark::State& state)
{
    std::string test_msg = "Test log message for benchmarking performance";
    for (auto benchmark_iteration : state)
    {
        benchmark::DoNotOptimize(benchmark_iteration);
        DltLogger::instance().log(DLT_LOG_INFO, test_msg);
    }
    state.SetItemsProcessed(state.iterations());
}
BENCHMARK(bm_dlt_logger_push)->Iterations(65536);

BENCHMARK_MAIN();