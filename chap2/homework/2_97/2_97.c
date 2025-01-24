#include <stdio.h>
#include <assert.h>
#include <limits.h>

#define SIZE (sizeof(unsigned))
#define FRAC_BITS 23
#define FRAC_MASK 0x7fffff
#define EXP_MASK 0xff
#define BIAS 127


typedef unsigned float_bits;

float_bits float_i2f(int i);


int main(void) {
	unsigned function_test, machine_test;
	unsigned u;
	float temp;

	for (u = 0; u != UINT_MAX; u++) {
		function_test = float_i2f(u);
		temp = (float) (int)u;
		machine_test = *(float_bits *) &temp;


		//assert(function_test == machine_test);

		if (function_test != machine_test) {
			printf("%032b, %08x, %f\n", function_test, function_test, *(float *) &function_test);
			printf("%032b, %08x, %f\n", machine_test, machine_test, *(float *) &machine_test);
			printf("%d\n", (int) u);
			printf("%u cases tested.\n", u);
			printf("First exception happend.\n");
			break;
		}
	}
	assert(function_test == machine_test);
	printf("All cases tested.\n");

	return 0;
}


float_bits float_i2f(int i) {
	unsigned sign = i & INT_MIN;
	unsigned exp = BIAS;
	unsigned frac = sign ? -i : i; // You don't need to concern the case INT_MIN, the sign var. would handle it.
	unsigned num_significant = (sizeof(int) << 3);
	unsigned residue, residue_mask;

	if (i == 0) return 0u;

	// Cutting out trailing zeros.
	// ex) 00000xxxxxx000000 ---> 00000xxxxxx
	while (frac & 0x1 == 0) {
		frac >>= 1;
		num_significant -= 1;
		exp += 1;
	}
	// Cutting out preceding zeros.
	// 00000xxxxxx --> xxxxxx
	for (int i = 0; ((0x80000000 >> i) & frac) == 0; i++)
		num_significant -= 1;

	// xxxxxx  --> x.xxxxx at most 24(23 + 1) significands
	exp += num_significant - 1;
	if (num_significant > FRAC_BITS + 1) {
		// Rounding
		residue_mask = ((1 << num_significant - (FRAC_BITS + 1)) - 1);
		residue = frac & residue_mask;
		frac >>= num_significant - (FRAC_BITS + 1);

		if (residue > (residue_mask + 1 >> 1))
			frac += 1;
		else if (residue == (residue_mask + 1 >> 1) && (frac & 0x01))
			frac += 1;

		// Additional process after rounding.
		exp += frac >> FRAC_BITS + 1; // When bit-up happens after rounding.
		frac >>= (frac >> FRAC_BITS + 1); // When rounded up, the rightmost bit must be 0.
	} else
		frac <<= (FRAC_BITS + 1) - num_significant;

	// Cutting out the leading one to be hidden.
	frac &= FRAC_MASK;
	// Applying bias.

	return sign | exp << FRAC_BITS | frac;
}
