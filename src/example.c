#include "example.h"

double f(double x) {
	double res = pow((x-4), 3);
	return res;
}

doubleErr_t readDouble(char** bufPtr, int sz) {
	// check if null ptr
	if (bufPtr == NULL) {
		fprintf(stderr, "Invalid memory address given to readInt().\n");
		err(false, true);
	}
	
	char* buf = *bufPtr;
	if (buf == NULL) {
		fprintf(stderr, "Invalid memory address given to readInt().\n");
		err(false, true);
	}

	char* res = fgets(buf, sz, stdin); 
	// check if fgets was successful
	if (res != buf) {
		fprintf(stderr, "fgets failed.\nError: %s\n", strerror(errno));
		err(false, true);
	}

	buf[strlen(buf) - 1] = 0; // remove nl and terminate

	char* endptr = NULL;
	double x = 0;
	x = strtod(buf, &endptr);
	if (endptr == buf) { // no digit was found
		fprintf(stderr, "Please enter a digit.\n");
		err(false, true);
	}

	err(x, false);
}