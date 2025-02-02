#!/bin/bash

RED='\033[0;31m'
GREEN='\033[0;32m'
YELLOW='\033[0;33m'
RESET='\033[0m'

PROGRAM="./push_swap"
checker="./checker_linux"
TESTS_PASSED=0
TESTS_FAILED=0
VERBOSE=0  
NUM_TESTS=100  
ARRAY_SIZE=500 
WORST_CASE=0
TIMEOUT=5  # Timeout in seconds for each test case

show_help() {
    echo "Usage: $0 [options]"
    echo
    echo "Options:"
    echo "  -v                          Enable verbose mode (logs additional details in 'tests.log')."
    echo "  -h                          Show this help message."
    echo "  -t [NUMBER]                 Specify the number of test cases to run (default: 100)."
    echo "  -s [NUMBER: 5, 100, 500]    Specify the size of each test case (default: 500 integers)."
    exit 0
}

run_test() {
    local INPUT=$1
    local SIZE=$2
    local status=0
    local CHECK

    # Run the program with a timeout
    local OUT
    OUT=$(timeout $TIMEOUT $PROGRAM $INPUT 2>&1)
    status=$?

    # Check if the command timed out
    if [[ $status -eq 124 ]]; then
        echo -e "TIMEOUT    ${RED}Test timed out${RESET}"
        if [[ $VERBOSE -eq 1 ]]; then
            echo "Input: $INPUT" >> tests.log
            echo "Output: TIMEOUT" >> tests.log
        fi
        ((TESTS_FAILED++))
        return
    fi

    # Check if the command segfaulted
    if [[ $status -eq 139 ]]; then
        echo -e "SEGFAULT  ${RED}Segmentation fault${RESET}"
        if [[ $VERBOSE -eq 1 ]]; then
            echo "Input: $INPUT" >> tests.log
            echo "Output: SEGFAULT" >> tests.log
        fi
        ((TESTS_FAILED++))
        return
    fi

    # Check if the command failed with another error
    if [[ $status -ne 0 ]]; then
        echo -e "FAILED     ${RED}Error running test (status: $status)${RESET}"
        if [[ $VERBOSE -eq 1 ]]; then
            echo "Input: $INPUT" >> tests.log
            echo "Output: Error (status: $status)" >> tests.log
        fi
        ((TESTS_FAILED++))
        return
    fi

    if [[ -z "$OUT" ]]; then
        CHECK=$(echo -n "" | $checker $INPUT 2>&1)
        if [[ $CHECK != "OK" ]]; then
            echo -e "FAILED     ${RED}$CHECK${RESET}"
            if [[ $VERBOSE -eq 1 ]]; then
                echo "Input: $INPUT" >> tests.log
                echo "Output: $CHECK" >> tests.log
            fi
            ((TESTS_FAILED++))
            return
        fi
    else
        # Check if the output is valid
        CHECK=$(echo "$OUT" | $checker $INPUT 2>&1)
        if [[ $CHECK != "OK" ]]; then
            echo -e "FAILED     ${RED}$CHECK${RESET}"
            if [[ $VERBOSE -eq 1 ]]; then
                echo "Input: $INPUT" >> tests.log
                echo "Output: $CHECK" >> tests.log
            fi
            ((TESTS_FAILED++))
            return
        fi
    fi


    # Process the output
    OUTPUT=$(echo "$OUT" | wc -l)
    if [[ $WORST_CASE < $OUTPUT ]]; then
        WORST_CASE=$OUTPUT
    fi

    if [[ $SIZE -eq 3 && $OUTPUT -le 3 ]]; then
        echo -e "PASSED     ${GREEN}$OUTPUT${RESET}"
        ((TESTS_PASSED++))
    elif [[ $SIZE -eq 3 && $OUTPUT -ge 3 ]]; then
        echo -e "WARNING    ${YELLOW}$OUTPUT${RESET}"
        ((TESTS_FAILED++))
    elif [[ $SIZE -eq 5 && $OUTPUT -le 12 ]]; then
        echo -e "PASSED     ${GREEN}$OUTPUT${RESET}"
        ((TESTS_PASSED++))
    elif [[ $SIZE -eq 100 && $OUTPUT -le 700 ]]; then
        echo -e "PASSED     ${GREEN}$OUTPUT${RESET}"
        ((TESTS_PASSED++))
    elif [[ $SIZE -eq 100 && $OUTPUT -ge 700 && $OUTPUT -lt 1500 ]]; then
        echo -e "WARNING    ${YELLOW}$OUTPUT${RESET}"
        ((TESTS_FAILED++))
    elif [[ $SIZE -eq 500 && $OUTPUT -lt 5500 ]]; then
        echo -e "PASSED     ${GREEN}$OUTPUT${RESET}"
        ((TESTS_PASSED++))
    elif [[ $SIZE -eq 500 && $OUTPUT -ge 5500 && $OUTPUT -lt 7000 ]]; then
        echo -e "WARNING    ${YELLOW}$OUTPUT${RESET}"
        ((TESTS_FAILED++))
    else
        echo -e "FAILED     ${RED}$OUTPUT${RESET}"
        ((TESTS_FAILED++))
    fi

    # Logging for verbose mode
    if [[ $VERBOSE -eq 1 && $status -eq 0 ]]; then
        echo "Input: $INPUT" >> tests.log
        LOG=$(echo $OUT)
        echo "Output: $LOG -> $OUTPUT" >> tests.log
    fi
}

while getopts ":vht:s:" opt; do
    case $opt in
        t)
            if ! [[ $OPTARG =~ ^[0-9]+$ ]]; then
                echo "Error: -t requires a numeric argument." >&2
                exit 1
            fi
            NUM_TESTS=$OPTARG
            ;;
        s)
            if [[ $OPTARG -eq 3 ||  $OPTARG -eq 5 || $OPTARG -eq 100 || $OPTARG -eq 500 ]]; then
                ARRAY_SIZE=$OPTARG
            else
                echo "Error: -s requires a value of 3, 5, 100, or 500." >&2
                exit 1
            fi
            ;;
        v)
            VERBOSE=1
            ;;
        h)
            show_help
            ;;
        *)
            echo "Invalid option: -$OPTARG" >&2
            show_help
            ;;
    esac
done

[[ $VERBOSE -eq 1 ]] && echo "Verbose mode enabled. Logging to 'tests.log'." && > tests.log

echo "Running $NUM_TESTS tests with array size $ARRAY_SIZE..."

for ((i = 1; i <= NUM_TESTS; i++)); do
    INPUT=$(python3 -c "import random; print(*random.sample(range(-2147483648, 2147483647), $ARRAY_SIZE))")
    run_test "$INPUT" "$ARRAY_SIZE"
done

echo -e "Worst Case: $WORST_CASE"
echo -e "Tests Passed: ${GREEN}$TESTS_PASSED${RESET}"
echo -e "Tests Failed: ${RED}$TESTS_FAILED${RESET}"
accuracy=$(echo "scale=2; $TESTS_PASSED / $NUM_TESTS * 100" | bc)
echo -e "Accuracy: ${GREEN}$accuracy%${RESET}"

if [[ $TESTS_FAILED -eq 0 ]]; then
    echo -e "${GREEN}All tests passed successfully!${RESET}"
else
    echo -e "${RED}Some tests failed. Please review the output.${RESET}"
fi