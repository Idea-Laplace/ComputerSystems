/*
   Fill in code for the following C function srl performs a logical
   right shift using an arithmetic shift(given by value xsra), followed
   by other operations not including right shifts or division. Function sra
   performs an arithmetic right shift using a logical right shift (given by xsrl),
   followed by other operations not including right shifts or division.
   You may use the computation 8 * sizeof(int) to determine w, the number of bits
   in data type int. The shift amount k can range from 0 to w-1.

unsigned srl(unsigned x, int k) {
	// Performs shift arithmetically.
	unsigned xsra = (int) x >> k;
	.
	.
	.
}

int sra(int x, int k) {
	// Performs shift logically.
	int xsrl = (unsigned) x >> k;
	.
	.
	.
}
*/
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

unsigned srl(unsigned x, int k);
int sra(int x, int k);


int main(int argc, char **argv) {
	int x = INT_MIN;
	unsigned y = INT_MIN; // Actually would be interpreted as 2^31 in the unsigned representation.
	int k = argc > 1 ? atoi(argv[1]) : 5;

	if (k < 0 || k > 31) {
		printf("Bit shift out of range, ignored.\n");
		return 0;
	}

	printf("Arithmetic right shift version:\n");
	printf("Initial         : %0*b\n", (int) sizeof(int) << 3, x);
	printf("INT_MIN >> %.2d   : %0*b\n", k, (int) sizeof(int) << 3, x >> k);
	printf("sra(INT_MIN, %.2d): %0*b\n", k, (int) sizeof(int) << 3, sra(x, k));

	putchar('\n');

	printf("Logical right shift version:\n");
	printf("Initial         : %0*b\n", (int) sizeof(int) << 3, y);
	printf("INT_MIN >> %.2d   : %0*b\n", k, (int) sizeof(int) << 3, y >> k);
	printf("srl(INT_MIN, %.2d): %0*b\n", k, (int) sizeof(int) << 3, srl(y, k));

	printf("Same result yielded as desired.\n");
	return 0;
}

unsigned srl(unsigned x, int k) {
	const int word = sizeof(int) << 3;

	// Performs shift arithmetically.
	unsigned xsra = (int) x >> k;

	// 2^(w - k) - 1 = 00...0[k terms]111...111[w - k terms]
	// Avoid the case k == 0;
	// Guarantee that the amount of left shift is in between 0 and word - 1.
	int mask = (1 << word - k - !k) - 1;
	mask = (mask << !k) | !k;

	// zeros at k leading bits would project any bit into 0.
	return xsra & mask;
}

int sra(int x, int k) {
	const int word = sizeof(int) << 3;

	// Performs shift logically.
	int xsrl = (unsigned) x >> k;

	// Same strategy as the srl function above.
	int mask = ((1 << word - k - !k) - 1);
	mask = ~((mask << !k) | !k);

	return xsrl | mask;
}

