
# Install CPM

set(CPM_LOCAL_PATH "${CMAKE_SOURCE_DIR}/cmake/CPM.cmake")

if(NOT EXISTS "${CPM_LOCAL_PATH}")
    message(STATUS "--------------- CPM not found --------------------")
    file(DOWNLOAD
        https://github.com/cpm-cmake/CPM.cmake/releases/latest/download/get_cpm.cmake
        "${CPM_LOCAL_PATH}"
        STATUS download_status
    )
    list(GET download_status 0 status_code)
    if(NOT status_code EQUAL 0)
        message(FATAL_ERROR "Download error CPM.cmake: ${download_status}")
    endif()
    message(STATUS "--------------- CPM installed --------------------")
endif()

include("${CPM_LOCAL_PATH}")

# Install google tests
find_package(GTest QUIET)
if(NOT GTest_FOUND)
    message(WARNING "-------- GTest not found after installation --------")
    message(STATUS "-------- Installing via CPM... --------")
    CPMAddPackage(
        NAME googletest
        GITHUB_REPOSITORY google/googletest
        GIT_TAG v1.17.0
        SYSTEM YES
        FIND_PACKAGE_ARGUMENTS CONFIG
    )
endif()

# Install google benchmark
find_package(benchmark QUIET)
if(NOT benchmark_FOUND)
    message(STATUS "--------------- benchmark not found --------------------")
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
endif()

# Install COVESA DLT
find_package(PkgConfig REQUIRED)

pkg_check_modules(DLT automotive-dlt)

message(STATUS "--------------- DLT found in system --------------------")
message(STATUS "DLT Include dirs: ${DLT_INCLUDE_DIRS}")
message(STATUS "DLT Libraries: ${DLT_LIBRARIES}")

if(NOT TARGET DLT::dlt)
    add_library(DLT::dlt INTERFACE IMPORTED)
    target_include_directories(DLT::dlt INTERFACE ${DLT_INCLUDE_DIRS})
    target_link_libraries(DLT::dlt INTERFACE ${DLT_LIBRARIES})
    target_link_directories(DLT::dlt INTERFACE ${DLT_LIBRARY_DIRS})
endif()

# Install yaml-cpp

find_package(yaml-cpp QUIET)
if(NOT yaml-cpp_FOUND)
    find_package(YAML-CPP QUIET)
    if(YAML-CPP_FOUND)
        set(yaml-cpp_FOUND TRUE)
    endif()
endif()

if(NOT yaml-cpp_FOUND)
    message(STATUS "--------------- yaml-cpp not found --------------------")
    CPMAddPackage(
        NAME yaml-cpp
        GITHUB_REPOSITORY jbeder/yaml-cpp
        GIT_TAG yaml-cpp-0.9.0
        SYSTEM YES
        FIND_PACKAGE_ARGUMENTS CONFIG
    )
    message(STATUS "--------------- yaml-cpp installed --------------------")

endif()

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
