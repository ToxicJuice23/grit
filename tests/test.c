#include "test.h"
// MODIFY AS YOU ADD TESTS
#define N_TESTS 1

TEST_FUNCTION(test_example)
    // do not touch these 2
    int fails = 0;
    int n_cases = 0;
    // modify from here

    TEST_CASE (example(0) > 100) {
        CRITICAL_FAIL // return -1 as critical failure
    }
    TEST_CASE (example(2) != 0) {
        FAIL
    } 
    TEST_CASE (example(0) != -5) {
        FAIL
    }
    // else if (conditon != expectation) fails++
    // DO NOT MODIFY BELOW
    RETURN_PERCENTAGE
}

int main(void) {
    printf("Starting tests...\n");
    // add your tests in this array as you go
    float(*tests[])(void) = {test_example};
    
    float p = run_tests(tests, N_TESTS);

    if ((int)p != 100) {
        printf("Failed with a total of %.2f%%\n", p);
        return 1;
    } else {
        printf("%sPassed every test!\n%s", GREEN, RESET);
    }
    return 0;
}