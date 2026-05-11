set(LOGGER_TARGET logger)

add_library(${LOGGER_TARGET}
    STATIC
        dlt_logger.h
        dlt_logger.cpp)


find_package(PkgConfig REQUIRED)
pkg_check_modules(DLT automotive-dlt)

if(NOT DLT_FOUND)
    message(STATUS "---------------DLT not found--------------------")

    CPMAddPackage(
        NAME DLT
        GITHUB_REPOSITORY GENIVI/dlt-daemon
        GIT_TAG v3.0.0
        SYSTEM YES
        FIND_PACKAGE_ARGUMENTS CONFIG
        OPTIONS
            "DLT_ENABLE_TESTING OFF"
            "DLT_ENABLE_INSTALL ON"
            "WITH_DLT_TESTS OFF"
            "WITH_SYSTEMD OFF"
    )
    if(TARGET dlt)
        set(DLT_LIBRARIES dlt)
        target_include_directories(${LOGGER_TARGET} PUBLIC "${DLT_SOURCE_DIR}/include")
        target_link_libraries(${LOGGER_TARGET} PUBLIC dlt)
    endif()
    message(STATUS "---------------DLT installed--------------------")
endif()


find_package(yaml-cpp QUIET)
if(NOT yaml-cpp_FOUND)
    message(STATUS "---------------yaml-cpp not found--------------------")


    CPMAddPackage(
        NAME yaml-cpp
        GITHUB_REPOSITORY jbeder/yaml-cpp
        GIT_TAG yaml-cpp-0.9.0
        SYSTEM YES
        FIND_PACKAGE_ARGUMENTS CONFIG
    )
    message(STATUS "---------------yaml-cpp installed--------------------")

endif()

CPMAddPackage(
    NAME concurrentqueue
    GITHUB_REPOSITORY cameron314/concurrentqueue
    GIT_TAG v1.0.5
    DOWNLOAD_ONLY YES
)

if (concurrentqueue_ADDED)
    add_library(concurrentqueue INTERFACE)
    target_include_directories(concurrentqueue INTERFACE ${concurrentqueue_SOURCE_DIR})
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

