
# Install CPM


set(CPM_SOURCE_CACHE "$ENV{HOME}/.cache/CPM" CACHE PATH "CPM Source Cache")

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
find_package(googletest QUIET)
if(NOT googletest_FOUND)
    CPMAddPackage(
        NAME googletest
        GITHUB_REPOSITORY google/googletest
        GIT_TAG v1.14.0
        SYSTEM YES
        FIND_PACKAGE_ARGUMENTS CONFIG
        FIND_PACKAGE googletest
    )
endif()

# Install benchmark
find_package(benchmark QUIET)
if(NOT benchmark_FOUND)
    message(STATUS "--------------- benchmark not found --------------------")
    CPMAddPackage(
        NAME benchmark
        GITHUB_REPOSITORY google/benchmark
        GIT_TAG v1.8.3
        SYSTEM YES
        FIND_PACKAGE_ARGUMENTS CONFIG
        FIND_PACKAGE benchmark
        OPTIONS
            "BENCHMARK_ENABLE_TESTING OFF"
            "BENCHMARK_ENABLE_INSTALL OFF"
    )
endif()

# Install COVESA DLT
find_package(PkgConfig REQUIRED)
pkg_check_modules(DLT automotive-dlt)

if(NOT DLT_FOUND)
       message(STATUS "-------- DLT not found in system. Installing via CPM... --------")

    CPMAddPackage(
        NAME dlt
        GITHUB_REPOSITORY COVESA/dlt-daemon
        GIT_TAG v3.0.0
        SYSTEM YES
        OPTIONS
            "DLT_ENABLE_TESTING OFF"
            "DLT_ENABLE_INSTALL OFF"
            "WITH_DLT_TESTS OFF"
            "WITH_SYSTEMD OFF"
    )

    # After CPM builds dlt, modify its interface directories to include both
    # the parent and subdirectory so <dlt/dlt.h> works and internal includes work
    if(TARGET dlt)
        # Clear existing includes and add both parent and dlt subdirectory
        set_target_properties(dlt PROPERTIES INTERFACE_INCLUDE_DIRECTORIES "")
        target_include_directories(dlt PUBLIC
            $<BUILD_INTERFACE:${dlt_SOURCE_DIR}/include>
            $<BUILD_INTERFACE:${dlt_SOURCE_DIR}/include/dlt>
            $<BUILD_INTERFACE:${dlt_BINARY_DIR}/include>
            $<BUILD_INTERFACE:${dlt_BINARY_DIR}/include/dlt>
        )
    endif()

    if(NOT TARGET Genivi::dlt)
        add_library(Genivi::dlt ALIAS dlt)
    endif()
else()
    message(STATUS "--------------- DLT found in system --------------------")

    if(NOT TARGET Genivi::dlt)
        add_library(Genivi::dlt INTERFACE IMPORTED)
        target_include_directories(Genivi::dlt INTERFACE ${DLT_INCLUDE_DIRS})
        target_link_libraries(Genivi::dlt INTERFACE ${DLT_LIBRARIES})
        target_link_directories(Genivi::dlt INTERFACE ${DLT_LIBRARY_DIRS})
    endif()
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
    CPMAddPackage(
        NAME yaml-cpp
        GITHUB_REPOSITORY jbeder/yaml-cpp
        GIT_TAG yaml-cpp-0.9.0
        SYSTEM YES
        FIND_PACKAGE_ARGUMENTS CONFIG
        FIND_PACKAGE yaml-cpp
    )

endif()

# Install concurrentqueue
find_package(concurrentqueue QUIET)
if(NOT concurrentqueue_FOUND)
    CPMAddPackage(
        NAME concurrentqueue
        GITHUB_REPOSITORY cameron314/concurrentqueue
        GIT_TAG v1.0.4
        SYSTEM YES
        DOWNLOAD_ONLY YES
    )
endif()

if (concurrentqueue_ADDED)
    add_library(concurrentqueue INTERFACE)
    target_include_directories(concurrentqueue INTERFACE ${concurrentqueue_SOURCE_DIR})
endif()
