#include <stdio.h>
#include <assert.h>


int main(void) {
	int x, y, z;
	double dx, dy, dz;
	double test1, test2;

	x = 0x40000001; // 2^30 + 1
	y = 0x00800001; // 2^23 + 1
	z = 0x00100001; // 2^20 + 1

	dx = (double) x;
	dy = (double) y;
	dz = (double) z;

	test1 = (dx * dy) * dz;
	test2 = dx * (dy * dz);

	printf("%064lb\n", *((unsigned long *) &test1));
	printf("%064lb\n", *((unsigned long *) &test2));
	assert((x * y) * z == x * (y * z));
	assert((dx * dy) * dz == dx * (dy * dz));


	return 0;
}


