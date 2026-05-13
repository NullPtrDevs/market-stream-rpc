#!/usr/bin/env bash

set -e

# shellcheck source=/dev/null
source "$(dirname "${BASH_SOURCE[0]}")/env.sh"

# This variables uses by build_project function.
# Do no change the names!
USE_THREAD_SANITIZER="OFF"
USE_ADDRESS_SANITIZER="OFF"
USE_COVERAGE="OFF"
USE_COVERAGE_HTML="OFF"
BUILD_TYPE="Debug"
CLEAN_BUILD="OFF"

# shellcheck source=/dev/null
source "$SCRIPT_DIR/build.sh"
build_project

echo "Formatting code..."
find "$SOURCE_DIR" -path "$BUILD_DIR" -prune -o -type f \( -name "*.cpp" -o -name "*.hpp" -o -name "*.h" \) -print0 | xargs -0 clang-format -i

echo "Running static analysis..."

find "$SOURCE_DIR" -path "$BUILD_DIR" -prune -o -type f \( -name "*.cpp" -o -name "*.h" -o -name "*.hpp" \)  -print0 | \
    xargs -0 -r run-clang-tidy \
    -p "$BUILD_DIR" \
    -header-filter=".*" \
    -extra-arg="-std=c++20" \
    -extra-arg="-Wall" \
    -extra-arg="-Wno-unknown-warning-option" \
                        2>/dev/null | \
                        awk -F: -v root="${SOURCE_DIR}/" '/warning:|error:/ { 
                            file=$1; line=$2; type=$4; 
                            sub(root, "", file);
                            gsub(/^[ \t]+|[ \t]+$/, "", type);                           
                            msg=$5; for(i=6; i<=NF; i++) msg=msg ":" $i;
                            gsub(/^[ \t]+/, "", msg);
                            error_key = file "_" line "_" msg;
                            if (seen[error_key]++) {
                                next;
                            }
                            printf "%s|%s|%s|%s\n", file, line, type, msg 
                        }' | column -t -s '|' -N "FILE,LINE,TYPE,DIAGNOSTIC MESSAGE" | less -S
