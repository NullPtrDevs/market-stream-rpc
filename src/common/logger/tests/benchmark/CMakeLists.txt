set(TARGET_NAME benchmark_logger)
add_executable(${TARGET_NAME} benchmark_logger.cpp)

find_package(benchmark REQUIRED)

target_include_directories(${TARGET_NAME} PRIVATE "${PROJECT_SOURCE_DIR}/src/")
target_link_libraries(${TARGET_NAME}
    PRIVATE
        benchmark::benchmark
        logger
        dlt
)