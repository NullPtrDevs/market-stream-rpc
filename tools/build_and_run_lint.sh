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

echo -e "${GREEN}------------------------------------------Formatting code------------------------------------------${NC}"

find "$SOURCE_DIR" -path "$BUILD_DIR" -prune -o -type f \( -name "*.cpp" -o -name "*.hpp" -o -name "*.h" \) -print0 | xargs -0 clang-format -i

echo -e "${GREEN}------------------------------------------Running static analysis------------------------------------------${NC}"

if [ ! -d "${LINT_REPORT}" ]; then
    mkdir -p "${LINT_REPORT}"
fi

run-clang-tidy \
  -clang-tidy-binary clang-tidy-18 \
  -j 4 \
  -p "$BUILD_DIR" \
  -header-filter="^${SOURCE_DIR}/.*" \
  -extra-arg="-std=c++20" \
  -extra-arg="-Wall" \
  -extra-arg="-Wno-unknown-warning-option" \
  "^${SOURCE_DIR}/.*" 2>/dev/null | \
awk -F: -v root="${SOURCE_DIR}/" '
  BEGIN {
    print "| FILE | LINE | TYPE | DIAGNOSTIC MESSAGE |"
    print "| :--- | :--- | :--- | :--- |"
  }
  /warning:|error:/ { 
    file = $1;
    line = $2; 
    type = $4; 
    
    if (file ~ /^\/usr\// || file ~ /^\/include\//) { next; }
    
    sub(root, "", file); 
    rel_path = "src/" file;
    
    gsub(/^[ \t]+|[ \t]+$/, "", type); 
    msg = $5; 
    for(i=6; i<=NF; i++) msg = msg ":" $i; 
    gsub(/^[ \t]+/, "", msg); 
    gsub(/\|/, "\\|", msg);
    
    error_key = file "_" line "_" msg; 
    if (seen[error_key]++) { next; } 
    
    file_link = sprintf("[%s](/%s#L%s)", file, rel_path, line);
    
    printf "| %s | %s | %s | %s |\n", file_link, line, type, msg 
  }' > "${LINT_REPORT}/clang_tidy_report.md"


