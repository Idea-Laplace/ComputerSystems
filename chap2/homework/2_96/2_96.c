#include <stdio.h>
#include <assert.h>
#include <limits.h>

#define SIZE (sizeof(unsigned))
#define FRAC_BITS 23
#define FRAC_MASK 0x7fffff
#define EXP_MASK 0xff
#define BIAS 127


typedef unsigned float_bits;


int float_f2i(float_bits f);


int main(void) {
	int function_test, machine_test;
	float temp;
	unsigned u;

	for (u = 0; u != UINT_MAX; u++) {
		function_test = float_f2i(u);
		temp = *(float *) &u;
		machine_test = (int) temp;

		assert(function_test == machine_test);

		if (u % 100000000 == 0 && !!u)
			printf("%u cases tested.\n", u);
	}
	assert(function_test == machine_test);
	printf("All cases tested.\n");

	return 0;
}


int float_f2i(float_bits f) {
	unsigned sign_bit = f & INT_MIN;
	unsigned exp_bits = f >> FRAC_BITS & EXP_MASK;
	unsigned frac_bits = f & FRAC_MASK;

	int exponent = exp_bits - BIAS + !exp_bits;
	int significand = frac_bits + (1 << FRAC_BITS); // We don't need to concern subnormal cases.
	int shifts = exponent - FRAC_BITS;

	if (exponent > 30)
		return INT_MIN;
	if (exponent < 0)
		return 0;

	if (shifts >= 0)
		significand <<= shifts;
	else
		significand >>= -shifts;

	return sign_bit ? -significand : significand;
}


