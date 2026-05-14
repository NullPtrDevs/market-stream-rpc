#!/usr/bin/env bash

# Generate coverage report, installed lcov needed.

set -e

# Include environment variables.
# shellcheck source=/dev/null
source "$(dirname "${BASH_SOURCE[0]}")/env.sh"

show_help() {
    echo "Build project, run tests and generate coverage report"
    echo "Usage: build_and_run_tests.sh [options]"
    echo "-------------------------------------------------------------------"
    echo "Options:"
    echo "  -ts, --tsanitize    Build with thread sanitizers"
    echo "  -as, --asanitize    Build with thread sanitizers"
    echo "  -r, --release       Build in Release mode (default is Debug)"
    echo "  -cov, --coverage    Generate coverage and open html report"
    echo "  -cl, --clean        Perform clean build"
    echo "  -sh, --shtml          Show html report in browser"
    echo "  -h, --help          Show this help message"
    echo "-------------------------------------------------------------------"
    echo "Please be aware that flag -c can conflict with -s."
    echo "Sanitizer can recognize coverage library as an error. Better don't use them both."
    echo "Do not use -ts with -as together. Compiler can use only one option."
    echo "If they used both, -as will be set as default."
    exit 0
}

# This variables uses by build_project function.
# Do no change the names!

USE_THREAD_SANITIZER="OFF"
USE_ADDRESS_SANITIZER="OFF"
BUILD_COVERAGE="OFF"
BUILD_TYPE="Debug"
SHOW_HTML_REPORT="OFF"
CLEAN_BUILD="OFF"

echo "--------------------------------Setup coverage dir---------------------------" 

# prepare coverage folder
rm -rf "${COVERAGE_DIR}"
mkdir -p "${COVERAGE_DIR}"

# parse parameters
while [[ "$#" -gt 0 ]]; do
    case $1 in
        -ts|--tsanitize) USE_THREAD_SANITIZER="ON"; shift ;;
        -as|--asanitize) USE_ADDRESS_SANITIZER="ON"; shift ;;
        -r|--release) BUILD_TYPE="Release"; shift ;;
        -cov|--coverage) BUILD_COVERAGE="ON"; shift ;;
        -cl|--clean) CLEAN_BUILD="ON"; shift ;;
        -sh|--shtml) SHOW_HTML_REPORT="ON"; shift ;;
        -h|--help) show_help ;;
        *) echo "Unknown parameter $1"; exit 1 ;;
    esac
done

if [[ "$USE_THREAD_SANITIZER" == "ON" ]] && [[ "$USE_ADDRESS_SANITIZER" == "ON" ]]; then
    echo "Both sanitizer is ON, use address sanitize by default"
    USE_THREAD_SANITIZER="OFF"
fi

echo "-------------------------------------------------------"
echo "Build Type: $BUILD_TYPE"
echo "Thread sanitizer:  $USE_THREAD_SANITIZER"
echo "Thread sanitizer:  $USE_ADDRESS_SANITIZER"
echo "Use coverage:  $BUILD_COVERAGE"
echo "Clean build:  $CLEAN_BUILD"
echo "Show html report:  $SHOW_HTML_REPORT"
echo "-------------------------------------------------------"

# Build project

# shellcheck source=/dev/null
source "$SCRIPT_DIR/build.sh"
build_project

# run all tests

cd "$BUILD_DIR"

# Just in case remove old *.gcda
find . -name "*.gcda" -delete

# Run tests and store junit report into specific folder
echo -e "${GREEN}--------------------------------Run tests---------------------------${NC}"

ctest --version
cmake --version

export GTEST_OUTPUT="xml:${BUILD_DIR}/junit_reports/"
ctest --output-on-failure -V

echo -e "${GREEN}--------------------------------Tests finished---------------------------${NC}"

if [ "$BUILD_COVERAGE" == "ON" ]; then

    # generate report
    echo -e "${GREEN}--------------------------------Generate coverage report---------------------------${NC}" 
    cd "${PROJECT_ROOT}"
    mkdir "${COVERAGE_DIR}/html"

    gcovr -r . \
        --filter 'src/' \
        --exclude '.*tests/.*\.cpp' \
        --exclude '.*benchmark/.*\.cpp' \
        --exclude '.*main.cpp' \
        --html-details "${COVERAGE_DIR}/html/index.html" \
        --xml-pretty \
        --output "${COVERAGE_DIR}/coverage.xml" \
        --gcov-ignore-parse-errors

    # Show html report if requested.
    if [ "$SHOW_HTML_REPORT" == "ON" ]; then
        if command -v xdg-open > /dev/null; then
        xdg-open "${COVERAGE_DIR}/html/index.html"
        elif command -v open > /dev/null; then
            open "${COVERAGE_DIR}/html/index.html"
        else
            echo "Report generated at: ${COVERAGE_DIR}/html/index.html"
        fi
    fi
fi

echo -e "${GREEN}--------------------------------Done---------------------------${NC}"

