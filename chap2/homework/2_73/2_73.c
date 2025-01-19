#include <stdio.h>
#include <limits.h>

int saturating_add(int x, int y);


int main(void) {
	int x, y, z, w;
	x = 0xffff0000;
	y = 0x80000000;
	z = 0x7fffffff;
	w = 0x1;

	printf("%x + %x = %x\n", x, x, saturating_add(x, x)); // Not overflow.
	printf("%x + %x = %x\n", y, y, saturating_add(y, y)); // Negative overflow.
	printf("%x + %x = %x\n", z, z, saturating_add(z, z)); // Positive overflow.
	printf("%x + %x = %x\n", w, w, saturating_add(w, w)); // Not overflow.

	return 0;
}


int saturating_add(int x, int y) {
	int word = sizeof(int) << 3;
	// Overflow happens iff the sign bit of x and y are identical and different from x + y.
	// 0xffffffff if overflow happened else 0x00000000.
	int overflow = ((x ^ (x + y)) & (y ^ (x + y))) >> word - 1;

	// Nonzero only when overflow did not happened.
	int normal = ~overflow & (x + y);

	// Without loss of generality, take x as the reference for the sign bit of operands.
    int p_saturation = ((overflow & ~x) >> word - 1) & INT_MAX;
	int n_saturation = ((overflow & x) >> word - 1) & INT_MIN;

	// 3 cases are exclusive repectively.
	return normal | p_saturation | n_saturation;
}
