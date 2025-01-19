#include <stdio.h>
#include <limits.h>

#define LEN 7

int fits_bits(int x, int n);
int better_solution_fits_bits(int x, int n);


int main(void) {
	int arr[LEN] = {0, 1, -1, 32767, 32768, INT_MAX, INT_MIN};

	for (int i = 0; i < LEN; i++) {
		printf("%d(%08x): %s representable with the short representation.\n",\
			arr[i], (unsigned) arr[i], fits_bits(arr[i], (int) sizeof(short) << 3) ? "" : "not");
	}

	for (int i = 0; i < LEN; i++) {
		printf("%d(%08x): %s representable with the short representation.\n",\
			arr[i], (unsigned) arr[i], better_solution_fits_bits(arr[i], (int) sizeof(short) << 3) ? "" : "not");
	}

	return 0;
}


// My answer
int fits_bits(int x, int n) {
	// The sign bit of n-bits: (n-1)th bit.
	// If the w-bits integer x can be represented as n-bit 2's complement,
	// then the x has a contagious (w - n + 1) bits consisting of exclusively 0 or 1
	// from the leftmost bit.

	int mask = ~((1 << (n - 1)) - 1); // 111...111[<-(n-1)th bit)]000...0000
	// if n = 0, then mask = 1111...111. if n = w, then mask = 100000....0000.


	return !(x & mask ^ mask) || !(x & mask);
}


// Better answer uploaded on the website.
int better_solution_fits_bits(int x, int n) {
	int w = sizeof(int) << 3;
	// 1. Erase the left w - n bits so that the information of the least n bits are conserved.
	// 2. Under the arithmetic right shift, the 'restored' bits would be either all ones or all zeros,
	//    according to the (n-1)th sign bit.
	// 3. x can be represented by n-bit 2's complement representation only when the left w-n bits consist
	//    of all zeros or ones, all of which are identical to the n-1th bit, the sign bit in the n-bit representation.
	return x << (w - n) >> (w - n) == x;
}
