#include "test.h"
// MODIFY AS YOU ADD TESTS
#define N_TESTS 1

TEST_FUNCTION(test_f)
    // do not touch these 2
    int fails = 0;
    int n_cases = 0;
    // modify from here

    TEST_CASE (f(0) > 100) {
        CRITICAL_FAIL // return -1 as critical failure
    }
    TEST_CASE (f(2) != 0) {
        FAIL
    } 
    TEST_CASE (f(0) != -5) {
        FAIL
    }
    // else if (conditon != expectation) fails++
    // DO NOT MODIFY BELOW
    RETURN_PERCENTAGE
}

int main(void) {
    printf("Starting tests...\n");
    // add your tests in this array as you go
    float(*tests[])(void) = {test_f};
    
    float perc = run_tests(tests, N_TESTS);

    if ((int)perc != 1) {
        printf("Failed with a total of %.2f%%\n", perc);
        return 1;
    } else {
        printf("%sPassed every test!\n%s", GREEN, RESET);
    }
    return 0;
}