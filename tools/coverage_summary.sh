#!/bin/bash
# Generate coverage summary for display in CI logs

set -e

# Check if coverage.info exists
if [ ! -f "build/coverage.info" ]; then
    echo "Error: coverage.info not found in build directory"
    echo "Please run 'make coverage' first"
    exit 1
fi

echo "==================================="
echo "Code Coverage Summary"
echo "==================================="
echo ""

# Display coverage summary
lcov --summary build/coverage.info 2>&1 | grep -E "lines\.\.\.\.\.\.|functions\.\.\.\."

echo ""
echo "==================================="
echo "Full report available at: build/coverage_report/index.html"
echo "==================================="
