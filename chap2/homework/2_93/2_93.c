#include <stdio.h>
#include <assert.h>
#include <math.h>
#include <stdlib.h>
#include <limits.h>

#define SIZE (sizeof(unsigned))
#define EXP_BITS 8
#define FRAC_BITS 23


typedef unsigned float_bits;


float_bits float_absval(float_bits f);


int main(void) {
	unsigned u;
	unsigned function_test, machine_test;
	float temp;

	for (u = 0; u != UINT_MAX; u++) {
		function_test = float_absval(u);
		temp = *(float *) &u < 0 ? -(*(float *) &u) : *(float *) &u;
		machine_test = *(unsigned *) &temp;

		assert(function_test == machine_test);

		if (u % 1000000000 == 0 && !!u)
			printf("Tested %u cases.\n", u);
	}

	assert(function_test == machine_test);
	printf("All cases were tested, no exception happend.\n");

	return 0;
}


float_bits float_absval(float_bits f) {
	unsigned sign = f >> SIZE - 1;  
	unsigned exp = f >> FRAC_BITS & 0xff;
	unsigned frac = f & 0x7fffff;

	if (exp != 0xff || frac == 0)
		// If sizeof(unsigned) == sizeof(float), then f & INT_MIN is just ok.
		sign = 0;

	return sign << SIZE - 1 | exp << FRAC_BITS | frac;
}
