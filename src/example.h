// make sure we don't include same file twice
#ifndef EXAMPLE_H
#define EXAMPLE_H
#include <stdio.h>
#include <stdint.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include "example.h"
#define true (uint8_t)1
#define false (uint8_t)0
#define err(x,y) return (doubleErr_t){x, y}

typedef struct {
	double Val;
	int Error; // 0 clear ; 1 error
} doubleErr_t;

double f(double x);
doubleErr_t readDouble(char** bufPtr, int sz);

#endif