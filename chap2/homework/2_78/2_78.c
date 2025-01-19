#include <stdio.h>
#include <assert.h>
#include <limits.h>


int divide_power2(int x, int k);

int main(void) {
	assert(9 / 4 == divide_power2(9, 2));
	assert(-9 / 4 == divide_power2(-9, 2));

	return 0;
}

int divide_power2(int x, int k) {
	int sign = !!(x & INT_MIN);
	int bias = (sign << k) - sign;

	return (x + bias) >> k;
}


