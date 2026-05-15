set(LOGGER_TARGET logger)

add_library(${LOGGER_TARGET}
    STATIC
        dlt_logger.h
        dlt_logger.cpp
        dlt_logger_config.h
        dlt_logger_config.cpp)

target_include_directories(${LOGGER_TARGET}
    PUBLIC
         ${CMAKE_CURRENT_SOURCE_DIR}
)

target_link_libraries(${LOGGER_TARGET}
    PUBLIC
        Genivi::dlt
        yaml-cpp
        concurrentqueue
        config_service)

add_subdirectory(tests/integration)

