#ifndef TEST_H
#define TEST_H

#include <stdio.h>
#include <example.h>
#include <stdlib.h>
#define RESET   "\033[0m"
#define BLACK   "\033[30m"      /* Black */
#define RED     "\033[31m"      /* Red */
#define GREEN   "\033[32m"      /* Green */
#define YELLOW  "\033[33m"      /* Yellow */
#define BLUE    "\033[34m"      /* Blue */
#define MAGENTA "\033[35m"      /* Magenta */
#define CYAN    "\033[36m"      /* Cyan */
#define WHITE   "\033[37m"      /* White */
#define TEST_CASE n_cases++; if
#define TEST_FUNCTION(x) float x(void) {
#define RETURN_PERCENTAGE return (float)(n_cases-fails)/(float)n_cases;
#define CRITICAL_FAIL return -1;
#define FAIL fails++;

// DO NOT MODIFY!!
float run_tests(float(**tests)(void), int n_tests) {
    float sum_perc = 0;
    float current_perc = 0;

    for (int i=0; i<n_tests; i++) {
        current_perc = (*tests[i])();
        if (current_perc == -1) {
            printf("%sTest #%d failed critically.\n%s", RED, i+1, RESET);
            exit(1);
        } else if ((int)current_perc != 1) {
            printf("%sTest #%d: %.2f%%\n%s", YELLOW, i+1, current_perc, RESET);
        } else {
            printf("%sPassed test #%d.\n%s", GREEN, i+1, RESET);
        }
        sum_perc += current_perc;
    }
    return sum_perc / n_tests;
}

#endif