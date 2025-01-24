#include <stdio.h>
#include <assert.h>
#include <limits.h>
#include <stdlib.h>

#define SIZE (sizeof(unsigned))
#define FRAC_BITS 23
#define EXP_MASK 0xff
#define FRAC_MASK 0x7fffff

typedef unsigned float_bits;


float_bits float_twice(float_bits f);


int main(void) {
	unsigned u;
	unsigned function_test, machine_test;
	float temp;

	printf("Test started.\n");
	for (u = 0; u != UINT_MAX; u++) {
		function_test = float_twice(u);
		temp = *(float *) &u;
		temp = temp * 2.0f;
		machine_test = *(unsigned *) &temp;

		// For debug purpose
		//printf("%032b\n", function_test);
		//printf("%032b\n", machine_test);
		//getchar();

		assert(function_test == machine_test);
		if (u % 1000000000 == 0 && u)
			printf("%u cases tested.\n", u);
	}
	assert(function_test == machine_test);
	printf("All cases tested, no exception happened.\n");
	return 0;
}


float_bits float_twice(float_bits f) {
	unsigned sign = f & INT_MIN;
	unsigned exp = f >> FRAC_BITS & EXP_MASK;
	unsigned frac = f & FRAC_MASK;

	// Both Inf and NaN cases.
	if (exp == 0xff)
		return f;
	// Inf when twiced
	else if (exp == 0xfe)
		return sign << SIZE - 1 | 0xff << FRAC_BITS;
	// Subnormal cases
	else if (exp == 0) {
		frac <<= 1;
		// Cases when the subnormal values are no more subnormal after twiced.
		exp = frac >> FRAC_BITS; 
		frac &= FRAC_MASK;
	} else
		exp += 1;

	//printf("%b %b %b\n", sign, exp, frac);
	return sign | exp << FRAC_BITS | frac;
}
