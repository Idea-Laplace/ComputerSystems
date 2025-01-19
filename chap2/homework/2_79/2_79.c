#include <stdio.h>
#include <limits.h>
#include <assert.h>


int mul3div4(int x);


int main(void) {
	int x = 2;
	assert(3 * x / 4 == mul3div4(x));
	assert(3 * INT_MIN / 4 == mul3div4(INT_MIN));
	assert(INT_MIN / 4 * 3 == mul3div4(INT_MIN)); // This should be false.
	return 0;
}


int mul3div4(int x) {
	int sign = !!(x & INT_MIN);
	int bias = (sign << 2) - sign;

	x = (x << 2) - x;
	return (x + bias) >> 2;
}

	
