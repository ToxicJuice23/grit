#include <stdio.h>
#include <stdint.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#define true (uint8_t)1
#define false (uint8_t)0
#define err(x,y) return (intErr_t){x, y}

typedef struct {
	int Val;
	int Error; // 0 clear ; 1 error
} intErr_t;

int f(int x) {
	double res = pow((x-4), 3);
	return (int)res;
}

intErr_t readInt(char** buf, int sz) {
	// check if null ptr
	if (buf == NULL) {
		fprintf(stderr, "Invalid memory address given to readInt().\n");
		err(false, true);
	}
	
	char* b = *buf;
	if (b == NULL) {
		fprintf(stderr, "Invalid memory address given to readInt().\n");
		err(false, true);
	}

	char* res = fgets(b, sz, stdin); 
	// check if fgets was successful
	if (res != b) {
		fprintf(stderr, "fgets failed.\nError: %s\n", strerror(errno));
		err(false, true);
	}

	b[strlen(b) - 1] = 0; // remove nl and terminate

	char* endptr = NULL;
	int x = 0;
	x = (int)strtol(b, &endptr, 10); // base 10
	if (endptr == b) { // no digit was found
		fprintf(stderr, "Please enter a digit.\n");
		err(false, true);
	}

	err(x, false);
}

int main(void) {
	char* buf = malloc(100);
	int invalid = true;
	int x = 0;
	while (invalid) {
		printf("f(x) = (x-4)^3\nx = ");
		intErr_t input = readInt(&buf, 100);
		invalid = input.Error;
		x = input.Val;
    }
	printf("f(%d) = %d\n", x, f(x));
	// the %d is a format specifier.
	/*
	* %d is int
	* %f is float
	* %lf is double
	* %s is string
	* %c is char
	* %u is unsigned
	*/
	// the format specifers tell the standard io functions what type to expect
	free(buf);
}

