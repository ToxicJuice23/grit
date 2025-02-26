// not necessairy for a c program but gives you access to input/output function
#include <stdio.h>
#include <math.h>

int f(int x) {
	double res = pow((x-4), 3);
	return (int)res; // (int) tells the program convert to int
	// CAUTION: YOU CANT CONVERT STRINGS TO INT USING CASTING
	// use strtol or other functions like sscanf for that.
}

// must define a main function so the program knows when to start
int main(void/* tell the program we dont take arguments for main*/)
{
	int x; // declare a variable
	printf("f(x) = (x-4)^3\nx = "); // print basic
	scanf("%d", &x); // the & operator means "address of". so &x is the memory address to x
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
}

