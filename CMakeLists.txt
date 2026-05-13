cmake_minimum_required(VERSION 3.23)

project(market-stream-rpc VERSION 0.1.0)

# Compiler options

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
# Install all dependent libraries

include(cmake_deps/Dependencies.cmake)

# Sources

add_subdirectory(src/common/spsc_queue)
add_subdirectory(src/common/logger)

# Unit tests

enable_testing()
add_subdirectory(src/common/spsc_queue/tests/ut)

# Benchmark tests

add_subdirectory(src/common/spsc_queue/tests/benchmark)
add_subdirectory(src/common/logger/tests/benchmark)

# For testing purposes, remove once it is not needed anymore.

# For testing purposes, remove once it is not needed anymore.

add_executable(main_cpp src/main.cpp)
target_link_directories(main_cpp
    PRIVATE
        src/common/spsc_queue
        src/common/logger
)

target_link_libraries(main_cpp
    PRIVATE
        spsc_lock_free_queue
        logger
)