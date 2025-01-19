#include <stdio.h>
#include <assert.h>
#include <limits.h>


int threefourths(int x);


int main(void) {
	assert(3 / 4 == threefourths(1));
	assert(9 / 4 == threefourths(3));
	assert(12 / 4 == threefourths(4));
	assert(-3 / 4 == threefourths(-1));
	assert(-9 / 4 == threefourths(-3));
	assert(-12 / 4 == threefourths(-4));
	assert(INT_MIN / 4 * 3 == threefourths(INT_MIN));
	return 0;
}


int  threefourths(int x) {
	// Seemingly, x - (x >> 2) looks like a key expression.
	// If x > 0, then x - (x >> 2) would be equal to or slightly larger than it should be, which is not desired.
	// If x < 0, then x - (x >> 2) would be equal to or slightly larger than it should be, which is desired.
	// Since (x >> 2) is subtracted from x, the bias is also reversed.

	int sign = !!(x & INT_MIN);
	int reversed_bias = (!sign << 2) - !sign;

	return x - (x + reversed_bias >> 2);
}





