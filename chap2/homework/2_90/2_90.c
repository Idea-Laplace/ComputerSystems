#include <stdio.h>
#define BIAS 127
#define FRAC_BITS 23
#define LEN 4


/* Returns a floating-point value that has identical bit representation
   as its unsigned input */
float u2f(unsigned u);

// Returns a float type number representing 2^x.
float fpwr2(int x);

int main(void) {
	int exponents[LEN] = {-150, -127, 31, 128};

	for (int i = 0; i < LEN; i++) {
		printf("%-70.50f\n", fpwr2(exponents[i]));
	}
	return 0;
}


float u2f(unsigned u) {
	return *((float *) &u);
}

float fpwr2(int x) {
	unsigned exp, frac;
	unsigned u;

	// Too small. Return 0.0f.
	// -126(bias adjusted minimal exponent) -23(fraction bits).
	if (x < (1 - BIAS) - FRAC_BITS) {
		exp = 0;
		frac = 0;
	} else if (x < 1 - BIAS) {
		exp = 0;
		frac = (1 << FRAC_BITS - 1) >> x + BIAS;
	} else if (x < 1 + BIAS) {
		exp = x + BIAS;
		frac = 0;
	} else {
		// Too big, return +infinity.
		exp = (BIAS << 1) + 1;
		frac = 0;
	}

	u = (exp << 23) | frac;
	return u2f(u);
}



