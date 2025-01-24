#include <stdio.h>
#include <assert.h>
#include <limits.h>
#include <stdlib.h>

#define SIZE (sizeof(unsigned))
#define FRAC_BITS 23
#define EXP_MASK 0xff
#define FRAC_MASK 0x7fffff

typedef unsigned float_bits;


float_bits float_half(float_bits f);


int main(void) {
	unsigned u;
	unsigned function_test, machine_test;
	float temp;

	printf("Test started.\n");
	for (u = 0; u != UINT_MAX; u++) {
		function_test = float_half(u);
		temp = *(float *) &u;
		temp = temp / 2.0f;
		machine_test = *(unsigned *) &temp;


		assert(function_test == machine_test);
		if (u % 1000000 == 0 && u) {
			// For debug purpose
			printf("%032b\n", function_test);
			printf("%032b\n", machine_test);
			//getchar();
			printf("%u cases tested.\n", u);
		}
	}
	assert(function_test == machine_test);
	printf("All cases tested, no exception happened.\n");
	return 0;
}


float_bits float_half(float_bits f) {
	unsigned sign = f & INT_MIN;
	unsigned exp = f >> FRAC_BITS & EXP_MASK;
	unsigned frac = f & FRAC_MASK;
	unsigned residue = f & 0x01;

	// Both Inf and NaN cases.
	if (exp == 0xff)
		return f;
	// Subnormal cases
	else if (exp == 0) {
		frac >>= 1;
		frac += frac & residue; // Round to even rule.
	} else if (exp == 1) {
		exp -= 1;
		frac >>= 1;
		frac += 1 << FRAC_BITS - 1;  // The hidden leading 1.
		frac += frac & residue;      // Round to even rule.

		exp += frac >> FRAC_BITS;    // Exception handling for fraction overflow after rounding
		frac &= FRAC_MASK;
	} else
		exp -= 1;

	return sign | exp << FRAC_BITS | frac;
}
