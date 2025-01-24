#include <assert.h>
#include <limits.h>
#include <math.h>
#include <stdio.h>

#define FB_SIZE 32
#define EXP_BITS 8
#define FRAC_BITS 23

typedef unsigned float_bits;

/* Compute -f, if f is NaN, then returns f. This function if for debugging. */
float_bits float_negate(float_bits f);

int main(void) {
	float_bits function_test;
	float_bits machine_test;
	float temp;

	printf("Test started.\n");
	for (unsigned u = 0; u != UINT_MAX; u++) {
		function_test = float_negate(u);
		temp = -(*(float *) &u);
		machine_test = *(float_bits *) &temp;

		// Direct logical comparisons between NaN representations always return false.
		// In my pc, even in the nan representations the sigm bits were converted.
		assert(function_test == machine_test);

		if (u % 1000000000 == 0 && !!u)
			printf("Tested %u cases.\n", u);
	}
	assert(function_test == machine_test);
	printf("All cases were tested, no exception happend.\n");

	return 0;
}

float_bits float_negate(float_bits f) {
	unsigned sign = f >> FB_SIZE - 1;
	unsigned exp = f >> FRAC_BITS & 0xff;
	unsigned frac = f & 0x7fffff;

	if (exp != 0xff || frac == 0)
		sign ^= 1;

	return sign << FB_SIZE - 1 | exp << FRAC_BITS | frac;
}

