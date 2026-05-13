set(LOGGER_TARGET logger)

add_library(${LOGGER_TARGET}
    STATIC
        dlt_logger.h
        dlt_logger.cpp)

if(TARGET dlt)
    set(DLT_LIBRARIES dlt)
    target_include_directories(${LOGGER_TARGET} PUBLIC "${DLT_SOURCE_DIR}/include")
    target_link_libraries(${LOGGER_TARGET} PUBLIC dlt)
endif()

target_include_directories(${LOGGER_TARGET}
    PUBLIC
        src/common/logger
        ${DLT_INCLUDE_DIRS}
)

target_link_libraries(${LOGGER_TARGET}
    PUBLIC
        yaml-cpp
        concurrentqueue)

add_subdirectory(tests/integration)

