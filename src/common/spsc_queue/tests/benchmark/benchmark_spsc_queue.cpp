
#include <benchmark/benchmark.h>

#include <chrono>
#include <format>
#include <iostream>
#include <thread>
#include <vector>

#include "spsc_lock_free_queue.h"

static void BM_Queue_push_pop(benchmark::State& state)
{
    int32_t input{42};
    int32_t output{0};
    spsc_queue::LockFreeQueueSPSC<int32_t> queue;
    for (auto _ : state)
    {
        benchmark::DoNotOptimize(input);
        queue.push(1);
        if (queue.pop(output))
        {
            benchmark::DoNotOptimize(output);
        }
        benchmark::ClobberMemory();
    }
}
BENCHMARK(BM_Queue_push_pop);

static void BM_Queue_LargeRange(benchmark::State& state)
{
    spsc_queue::LockFreeQueueSPSC<int32_t> q;
    for (auto _ : state)
    {
        for (int32_t i = 0; i < state.range(0); ++i)
        {
            q.push(i);
        }
        for (int32_t i = 0; i < state.range(0); ++i)
        {
            int32_t val{0};
            q.pop(val);
        }
    }
}
// Run this test with 1024 and 4096 items per iteration
BENCHMARK(BM_Queue_LargeRange)->Arg(1024)->Arg(4096);

static void BM_Queue_Complexity(benchmark::State& state)
{
    spsc_queue::LockFreeQueueSPSC<int32_t> q;
    for (auto _ : state)
    {
        for (int32_t i = 0; i < state.range(0); ++i)
        {
            q.push(i);
        }
        for (int32_t i = 0; i < state.range(0); ++i)
        {
            int32_t val{0};
            q.pop(val);
        }
    }
    state.SetComplexityN(state.range(0));
}
BENCHMARK(BM_Queue_Complexity)->RangeMultiplier(2)->Range(128, 4096)->Complexity(benchmark::oN);

static void BM_SPSC_Queue_Latency(benchmark::State& state)
{
    spsc_queue::LockFreeQueueSPSC<int32_t> queue;
    const int32_t num_iterations = state.range(0);

    for (auto _ : state)
    {
        // We start a consumer thread for each iteration of the benchmark
        std::thread consumer(
            [&]()
            {
                int32_t element{0};
                for (int32_t j = 0; j < num_iterations; ++j)
                {
                    while (!queue.pop(element))
                    {
                        // Busy wait if queue is empty
                    }
                }
            });

        // Producer (the benchmark thread)
        for (int32_t i = 0; i < num_iterations; ++i)
        {
            while (!queue.push(i))
            {
                // Busy wait if queue is full
            }
        }

        consumer.join();
    }

    // Set total items processed to calculate throughput
    state.SetItemsProcessed(state.iterations() * num_iterations);
}

// Register the benchmark to test different queue workloads
BENCHMARK(BM_SPSC_Queue_Latency)->Range(100, 10000);

static void BM_SPSC_Queue(benchmark::State& state)
{
    static spsc_queue::LockFreeQueueSPSC<int32_t> queue;

    if (state.thread_index() == 0)
    {
        // Producer
        for (auto _ : state)
        {
            while (!queue.push(1))
            {
                asm volatile("pause");
            }
        }
    }
    else
    {
        // Consumer
        for (auto _ : state)
        {
            int32_t val;
            while (!queue.pop(val))
            {
                asm volatile("pause");
            }
            benchmark::DoNotOptimize(val);
        }
    }
}
BENCHMARK(BM_SPSC_Queue)->Threads(2);

BENCHMARK_MAIN();
