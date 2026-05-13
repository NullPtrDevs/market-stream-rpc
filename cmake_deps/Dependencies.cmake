
# Install CPM

set(CPM_LOCAL_PATH "${CMAKE_SOURCE_DIR}/cmake/CPM.cmake")

if(NOT EXISTS "${CPM_LOCAL_PATH}")
    message(STATUS "---------------CPM not found--------------------")
    file(DOWNLOAD
        https://github.com/cpm-cmake/CPM.cmake/releases/latest/download/get_cpm.cmake
        "${CPM_LOCAL_PATH}"
        STATUS download_status
    )
    list(GET download_status 0 status_code)
    if(NOT status_code EQUAL 0)
        message(FATAL_ERROR "Download error CPM.cmake: ${download_status}")
    endif()
    message(STATUS "---------------CPM installed--------------------")
endif()

include("${CPM_LOCAL_PATH}")

# Install google tests
CPMAddPackage(
  NAME googletest
  GITHUB_REPOSITORY google/googletest
  GIT_TAG v1.17.0
  SYSTEM YES
  FIND_PACKAGE_ARGUMENTS CONFIG
)

# Install google benchmark
CPMAddPackage(
    NAME benchmark
    GITHUB_REPOSITORY google/benchmark
    GIT_TAG        v1.9.5
    SYSTEM YES
    FIND_PACKAGE_ARGUMENTS CONFIG
    OPTIONS
        "BENCHMARK_ENABLE_TESTING OFF"
        "BENCHMARK_ENABLE_INSTALL OFF"
)


# Install COVESA DLT

find_package(PkgConfig REQUIRED)
pkg_check_modules(DLT automotive-dlt)

if(NOT DLT_FOUND)
    message(STATUS "---------------DLT not found--------------------")

    CPMAddPackage(
        NAME DLT
        GITHUB_REPOSITORY COVESA/dlt-daemon
        GIT_TAG v3.0.0
        SYSTEM YES
        FIND_PACKAGE_ARGUMENTS CONFIG
        OPTIONS
            "DLT_ENABLE_TESTING OFF"
            "DLT_ENABLE_INSTALL ON"
            "WITH_DLT_TESTS OFF"
            "WITH_SYSTEMD OFF"
    )
  
    message(STATUS "---------------DLT installed--------------------")
endif()

# Install yaml-cpp
CPMAddPackage(
    NAME yaml-cpp
    GITHUB_REPOSITORY jbeder/yaml-cpp
    GIT_TAG yaml-cpp-0.9.0
    SYSTEM YES
    FIND_PACKAGE_ARGUMENTS CONFIG
)

# Install concurrentqueue
CPMAddPackage(
    NAME concurrentqueue
    GITHUB_REPOSITORY cameron314/concurrentqueue
    GIT_TAG v1.0.5
    SYSTEM YES
    DOWNLOAD_ONLY YES
    FIND_PACKAGE_ARGUMENTS CONFIG
)

if (concurrentqueue_ADDED)
    add_library(concurrentqueue INTERFACE)
    target_include_directories(concurrentqueue INTERFACE ${concurrentqueue_SOURCE_DIR})
endif()
