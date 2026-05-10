#!/usr/bin/env bash

set -e

# shellcheck source=/dev/null
source "$(dirname "${BASH_SOURCE[0]}")/env.sh"

echo "Formatting code..."
find "$SOURCE_DIR" -path "$BUILD_DIR" -prune -o -type f \( -name "*.cpp" -o -name "*.hpp" -o -name "*.h" \) -print0 | xargs -0 clang-format -i

echo "Running static analysis..."


# -j "$(nproc)" \ use it if you have powerful CPU
find "$SOURCE_DIR" -path "$BUILD_DIR" -prune -o -type f -name "*.cpp" -print0 | xargs -0 -r run-clang-tidy \
    -p "$BUILD_DIR" \
    -header-filter="^${SOURCE_DIR}/.*" \
    -extra-arg="-isystem${BUILD_DIR}/_deps"


