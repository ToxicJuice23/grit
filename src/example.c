#include "example.h"

int example(int x) {
	// example function
	/* f(x) {
	 * 		x = 2: 0
	 *		else: 2x - 5
	 * }
	*/
	if (x == 2)
		return 0;
	return (2 * x) - 5;
}