#include <stdio.h>
#include <example.h>
#define RESET   "\033[0m"
#define BLACK   "\033[30m"      /* Black */
#define RED     "\033[31m"      /* Red */
#define GREEN   "\033[32m"      /* Green */
#define YELLOW  "\033[33m"      /* Yellow */
#define BLUE    "\033[34m"      /* Blue */
#define MAGENTA "\033[35m"      /* Magenta */
#define CYAN    "\033[36m"      /* Cyan */
#define WHITE   "\033[37m"      /* White */
#define N_TESTS 1 // INCREMENT THIS NUMBER WITH NUMBER OF test_x FUNCTIONS

// float test_{function_name}(void) should return the percentage of success

float test_f(void) {
    int fails = 0;
    int n_cases = /* CHANGE AS YOU ADD CASES*/1;
    // ADD CASES HERE LIKE SO
    // MAKE SURE TO ADD CRITICAL FAILURES FIRST.
    if (f(0) > 100) {
        return -1; // return -1 as critical failure
    } else if (f(2) != 0) {
        fails++;
    } else if (f(0) != -5) {
        fails++;
    }
    // else if (conditon != expectation) fails++
    // DO NOT MODIFY BELOW
    return (float)(n_cases-fails)/(float)n_cases;
}

// DO NOT MODIFY!!
float run_tests(float(**tests)(void), int n_tests) {
    float sum_perc = 0;
    float current_perc = 0;

    for (int i=0; i<n_tests; i++) {
        current_perc = (*tests[i])();
        if ((int)current_perc == -1) {
            printf("%sTest #%d failed critically.\n%s", RED, i+1, RESET);
        } else if ((int)current_perc != 1) {
            printf("%sTest #%d: %.2f%%\n%s", YELLOW, i+1, current_perc, RESET);
        } else {
            printf("%sPassed test #%d.\n%s", GREEN, i+1, RESET);
        }
        sum_perc += current_perc;
    }
    return sum_perc / n_tests;
}

int main(void) {
    printf("Starting tests...\n");
    float(*tests[N_TESTS])(void) = {test_f};
    
    float perc = run_tests(tests, N_TESTS);

    if ((int)perc != 1) {
        printf("Failed with a total of %.2f%%\n", perc);
        return 1;
    } else {
        printf("%sPassed!!\n%s", GREEN, RESET);
    }
    return 0;
}