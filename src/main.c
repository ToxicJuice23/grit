#include "example.h"

int main(void) {
	char* buf = malloc(100);
	int invalid = true;
	double x = 0;
	while (invalid) {
		printf("f(x) = (x-4)^3\nx = ");
		doubleErr_t input = readDouble(&buf, 100);
		invalid = input.Error;
		x = input.Val;
    }
	printf("f(%.2lf) = %lf\n", x, f(x));
	free(buf);
}