#include <benchmark/benchmark.h>

#include <string>

#include "common/logger/dlt_logger.h"
#include "common/spsc_queue/spsc_lock_free_queue.h"

struct LogFixture
{
    LogFixture()
    {
        DltLogger::instance().init("BENCH", "Benchmark App");
    }
    ~LogFixture()
    {
        std::this_thread::sleep_for(std::chrono::milliseconds(500));

        DltLogger::instance().stop();
    }
};
static LogFixture global_fix;

static void BM_DltLogger_Push(benchmark::State& state)
{
    std::string test_msg = "Test log message for benchmarking performance";
    for (auto _ : state)
    {
        DltLogger::instance().log(DLT_LOG_INFO, test_msg);
    }
    state.SetItemsProcessed(state.iterations());
}
BENCHMARK(BM_DltLogger_Push)->Iterations(65536);

BENCHMARK_MAIN();