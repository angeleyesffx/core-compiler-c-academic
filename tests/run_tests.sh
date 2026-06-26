#!/usr/bin/env bash
# Test runner for the Mini Pascal compiler.
#
# Test levels covered:
#   UNIT   — tests/unit/test_lexer  (DFA component in isolation)
#   SYSTEM — tests/valid/*.txt      (full pipeline, valid programs)
#   SYSTEM — tests/invalid/*.txt    (full pipeline, rejection expected)
#
# For invalid tests, an optional .expected_err file specifies the exact
# string that must appear in stderr (used for regression tests).

COMPILER="${1:-./compiler}"
UNIT_BIN="tests/unit/test_lexer"
TESTS_DIR="$(dirname "$0")"
PASS=0
FAIL=0

RED='\033[0;31m'
GREEN='\033[0;32m'
NC='\033[0m'

pass() { printf "${GREEN}PASS${NC} %s\n" "$1"; PASS=$((PASS+1)); }
fail() { printf "${RED}FAIL${NC} %s — %s\n" "$1" "$2"; FAIL=$((FAIL+1)); }

TMP_OUT=$(mktemp)
TMP_ERR=$(mktemp)
cleanup() { rm -f "$TMP_OUT" "$TMP_ERR"; }
trap cleanup EXIT

# ------------------------------------------------------------------ #
# UNIT TESTS — lexer component in isolation                           #
# ------------------------------------------------------------------ #
printf "\n=== Unit Tests ===\n"

if [ ! -f "$UNIT_BIN" ]; then
    fail "unit/test_lexer" "binary not found — run 'make test' to build it"
else
    "$UNIT_BIN" > "$TMP_OUT" 2> "$TMP_ERR"
    exit_code=$?
    # Print individual results (each line already has PASS/FAIL prefix)
    grep -E "^  (PASS|FAIL)" "$TMP_OUT" || true
    summary=$(grep "^Results:" "$TMP_OUT" || echo "")
    if [ "$exit_code" -eq 0 ]; then
        pass "unit/test_lexer ($summary)"
    else
        fail "unit/test_lexer" "$summary"
    fi
fi

# ------------------------------------------------------------------ #
# SYSTEM TESTS — valid programs                                       #
# ------------------------------------------------------------------ #
printf "\n=== System Tests: valid programs ===\n"

for input in "$TESTS_DIR/valid"/*.txt; do
    name=$(basename "$input" .txt)
    expected="$TESTS_DIR/valid/${name}.expected"

    if [ ! -f "$expected" ]; then
        fail "valid/$name" "missing .expected file"
        continue
    fi

    "$COMPILER" "$input" > "$TMP_OUT" 2> "$TMP_ERR"
    exit_code=$?

    if [ "$exit_code" -ne 0 ]; then
        fail "valid/$name" "exit $exit_code — $(cat "$TMP_ERR")"
        continue
    fi

    if diff -q "$TMP_OUT" "$expected" > /dev/null 2>&1; then
        pass "valid/$name"
    else
        fail "valid/$name" "output mismatch"
        diff "$TMP_OUT" "$expected" | head -10
    fi
done

# ------------------------------------------------------------------ #
# SYSTEM TESTS — invalid programs                                     #
# If a .expected_err file exists, stderr must contain that pattern.  #
# This is used for regression tests where the exact error matters.   #
# ------------------------------------------------------------------ #
printf "\n=== System Tests: invalid programs ===\n"

for input in "$TESTS_DIR/invalid"/*.txt; do
    name=$(basename "$input" .txt)
    expected_err="$TESTS_DIR/invalid/${name}.expected_err"

    "$COMPILER" "$input" > "$TMP_OUT" 2> "$TMP_ERR"
    exit_code=$?

    if [ "$exit_code" -eq 0 ]; then
        fail "invalid/$name" "expected failure, but compiler succeeded"
        continue
    fi

    if ! grep -qi "error" "$TMP_ERR"; then
        fail "invalid/$name" "exit $exit_code but no 'error' in stderr"
        continue
    fi

    # If a specific error pattern is required, verify it
    if [ -f "$expected_err" ]; then
        pattern=$(cat "$expected_err")
        if grep -qF "$pattern" "$TMP_ERR"; then
            pass "invalid/$name (pattern: '$pattern')"
        else
            fail "invalid/$name" "stderr missing pattern '$pattern' — got: $(cat "$TMP_ERR")"
        fi
    else
        pass "invalid/$name"
    fi
done

# ------------------------------------------------------------------ #
printf "\n=====================================\n"
printf "Results: %d passed, %d failed\n" "$PASS" "$FAIL"
[ "$FAIL" -eq 0 ]
