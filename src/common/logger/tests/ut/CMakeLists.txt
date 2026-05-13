add_executable(test_logger test_logger.cpp)

target_link_libraries(test_logger PRIVATE GTest::gtest_main logger dlt)

target_include_directories(test_logger
    PRIVATE
        "${PROJECT_SOURCE_DIR}/src/"
        ${DLT_INCLUDE_DIRS}
)

include(GoogleTest)
gtest_discover_tests(test_logger)
