#include <stdio.h>
#include <assert.h>
#include <math.h>

int main(void) {
	unsigned test_inf = 0x7f800000;
	unsigned test_nan = 0x7f900000;

	float f_inf = *(float *) &test_inf;
	float f_nan = *(float *) &test_nan;

	assert(isinf(f_inf) && isnan(f_nan));

	printf("Initial value.\n");
	printf("%08x\t %08x\n", test_inf, test_nan);

	f_inf += 1;
	f_nan += 1;

	printf("Add 1\n");
	printf("%08x\t %08x\n", *(unsigned *) &f_inf, *(unsigned *) &f_nan);

	f_inf *= -1;
	f_nan *= -1;
	printf("Negation\n");
	printf("%08x\t %08x\n", *(unsigned *) &f_inf, *(unsigned *) &f_nan);

	return 0;
}

