#include <stdio.h>
#include <assert.h>
#include <limits.h>


int tsub_ok(int x, int y);


int main(void) {
	assert(tsub_ok(INT_MIN, INT_MIN));
	assert(!tsub_ok(1, INT_MIN));
	assert(tsub_ok(-1, INT_MIN));
	assert(tsub_ok(1, -1));
	return 0;
}


int tsub_ok(int x, int y) {
	// Note that -INT_MIN == INT_MIN;
	// Actually, when it comes to INT_MIN, likes 0, whether the operator is addition or subration
	// makes do difference. 0 and INT_MIN have a symmerty property on addition and subtraction.
	// Focus on the leftmost(sign) bit operation.
	// The key expression is the (-y & (y ^ -y)); the sign bit of y ^ -y is 1 except INT_MIN,
	/*
	                          | Nonnegative(0) | Negative(except INT_MIN) | INT_MIN |
	   ------------------------------------------------------------------------------
	   |   sign_bit(y)        |    0(0)        |             1            |    1    |
	   ------------------------------------------------------------------------------    
	   |   sign_bit(-y)       |    1(0)        |             0            |    1    |
	   ------------------------------------------------------------------------------
	   | sign_bit(y ^ -y)     |    1(0)        |             1            |    0    |
	   ------------------------------------------------------------------------------
	   | s_bit(-y & (y ^ -y)) |    1(0)        |             0            |    0    |
	   ------------------------------------------------------------------------------
	*/

	int word = sizeof(int) << 3;
	int overflow = (x ^ (x - y)) & ((-y & (y ^ -y)) ^ (x - y)) >> word - 1;

	return !overflow;
}
