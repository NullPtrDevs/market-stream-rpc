add_executable(test_logger test_logger.cpp)

target_link_libraries(test_logger PRIVATE GTest::gtest_main logger dlt)

target_include_directories(test_logger
    PRIVATE
        "${PROJECT_SOURCE_DIR}/src/"
        ${DLT_INCLUDE_DIRS}
)

include(GoogleTest)
gtest_discover_tests(test_logger)

add_executable(test_dlt_logger_config
                test_dlt_logger_config.cpp)

target_include_directories(test_dlt_logger_config PRIVATE ${CMAKE_SOURCE_DIR}/src/common/logger)
target_link_libraries(test_dlt_logger_config 
                        PRIVATE
                        GTest::gtest_main
                        logger)

file(COPY ${CMAKE_CURRENT_SOURCE_DIR}/resources
     DESTINATION ${CMAKE_CURRENT_BINARY_DIR}
)

gtest_discover_tests(test_dlt_logger_config)
