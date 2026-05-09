cmake_minimum_required(VERSION 3.23)

project(market-stream-rpc VERSION 0.1.0)

# Compiler options

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Install all dependent libraries

include(cmake_deps/Dependencies.cmake)

# Sources

add_subdirectory(src/common/spsc_queue)

# Unit tests

enable_testing()
add_subdirectory(src/common/spsc_queue/tests/ut)

# Benchmark tests

add_subdirectory(src/common/spsc_queue/tests/benchmark)