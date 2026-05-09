
# Install CPM

set(CPM_LOCAL_PATH "${CMAKE_SOURCE_DIR}/cmake/CPM.make")

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

# Check for GTest

find_package(GTest REQUIRED)

# Install google benchmark

find_package(benchmark CONFIG QUIET)
if(NOT benchmark_FOUND)
    CPMAddPackage(
        NAME benchmark
        GITHUB_REPOSITORY google/benchmark
        GIT_TAG        v1.9.5
        SYSTEM YES
        OPTIONS
            "BENCHMARK_ENABLE_TESTING OFF"
            "BENCHMARK_ENABLE_INSTALL OFF"
    )
    message(STATUS "------------------------ benchmark installed--------------------------------")
endif()