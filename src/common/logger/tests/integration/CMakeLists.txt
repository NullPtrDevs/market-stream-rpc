add_executable(logger_test logger_test.cpp)
target_link_libraries(logger_test
    PRIVATE
        logger
        dlt
)

target_include_directories(logger_test
    PRIVATE
        "${PROJECT_SOURCE_DIR}/src/"
        ${DLT_INCLUDE_DIRS}
)