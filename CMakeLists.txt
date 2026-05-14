cmake_minimum_required(VERSION 3.23)

project(market-stream-rpc VERSION 0.1.0)

# Compiler options
# C++ 20
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
# Application configuration file path.
add_compile_definitions(DEFAULT_CONFIG_PATH="${CMAKE_CURRENT_SOURCE_DIR}/config/config.yaml")

# Install all dependent libraries
include(cmake_deps/Dependencies.cmake)

# Add coverage flag to all targets if needed.
# That how we can get whole project coverage.
# CMAKE_CXX_FLAGS defined in build.sh, use .tools/build.sh -cov,
# or tools/build_and_run_tests.sh -cov for proper settings.
if(${CMAKE_CXX_FLAGS} MATCHES "coverage")
    message(INFO "-------------------------------------- Add coverage options-----------------------------------")
    add_compile_options(--coverage -O0 -g)
    add_link_options(--coverage)
endif()

# Sources
add_subdirectory(src/common/spsc_queue)
add_subdirectory(src/common/logger)
add_subdirectory(src/common/config_service)

# Unit tests
enable_testing()
add_subdirectory(src/common/spsc_queue/tests/ut)
add_subdirectory(src/common/logger/tests/ut)
add_subdirectory(src/common/config_service/tests/ut)

# Benchmark tests
add_subdirectory(src/common/spsc_queue/tests/benchmark)
add_subdirectory(src/common/logger/tests/benchmark)

# For testing purposes, remove once it is not needed anymore.

# Build exe
add_executable(main_cpp src/main.cpp)
# For testing purposes, remove once it is not needed anymore.
target_link_directories(main_cpp PRIVATE src/common/logger)
target_include_directories(main_cpp PRIVATE src/common/config_service src/common/logger)
target_link_libraries(main_cpp PRIVATE spsc_lock_free_queue logger config_service)
