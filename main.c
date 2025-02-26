#include <stdio.h>
#include <stdint.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
#define true (uint8_t)1
#define false (uint8_t)0
// not necessairy for a c program but gives you access to input/output function

int f(int x) {
	double res = pow((x-4), 3);
	return (int)res; // (int) tells the program convert to int
	// CAUTION: YOU CANT CONVERT STRINGS TO INT USING CASTING
	// use strtol or other functions like sscanf for that.
}

// must define a main function so the program knows when to start
int main(void) { // tell the program we dont take arguments for main
	char* buf = malloc(100);
	uint8_t done = false;
	int x = 0; // declare a variable
	while (!done) {
		printf("f(x) = (x-4)^3\nx = "); // print basic


		char* res = fgets(buf, 100, stdin); // read all the input so that we can ignore extra chars

		// check if fgets was successful
		if (res != buf) {
			fprintf(stderr, "fgets failed.\n");
			continue;
		}

		buf[strlen(buf) - 1] = 0; // remove the newline so we can use it again and fgets will wait for us
		// complicated process to safely convert to int
		char* endptr = NULL;
		x = (int)strtol(buf, &endptr, 10); // base 10
		if (endptr == buf) { // no digit was found
			fprintf(stderr, "Please enter a digit.\n");
			continue;
		}
		done = true;
    	}
    	// the opposite of & is *
	// for example:
	// *(&x) cancels out because * tells c to go look at that memory address
	// That was pointer basics for you lol

	// scanf needs the address of x so it can modify the value. Otherwise the functions simply gets a copy
	int result = f(x);
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

