/*
   Write code to implement the following function:

   // Generate mask indicating leftmost 1 in x. Assume w = 32.
   // For example, 0xff00 -> 0x8000, and 0x6600 --> 0x4000.
   // If x = 0, then return 0.

   int leftmost_one(unsigned x);

   Your function should follow the bit-level integer coding rules
   except that you may assume that the data type int has w=32 bits.

   Your code should contain a total of at most 15 arithmetic, bitwise,
   and logical operations.

   Hint: First transform x into a bit vector of the form [00000...11111].
*/

#include <stdio.h>
#include <limits.h>

#define LEN 5

int leftmost_one(unsigned x);


int main(void) {
	unsigned arr[LEN] = {0, 1, 0xff00, 0x6600, INT_MIN};

	printf("Leftmost one\n");
	for (int i = 0; i < LEN; i++) {
		printf("%08x: %08x\n", arr[i], leftmost_one(arr[i]));
		printf("%032b:\n%032b\n", arr[i], leftmost_one(arr[i]));
	}

	return 0;
}

int leftmost_one(unsigned x) {
	// Fill the right side of the leftmost one by itself.
	// 10 operations, 5 '|' and 5 '>>'
	x |= (x >> 1); // Ensure that the bit representation is [00..0011xxxx].
	x |= (x >> 2); // [00...00 1111 xxxx...x].
	x |= (x >> 4); // [00...00 11111111 xxxx...x].
	x |= (x >> 8); // [00...00 1111111111111111 xxxx...x].
	x |= (x >> 16); // [00...00 11111111111111111111111111111111].

	// If the 'filled' x were actually 0, it would do nothing.
	// Otherwise, it would return the desired value. since (2^k - 1) + 1 = 2^k.
	// 3 operations, 1 '>>' and 2 '!'.
	x = (x >> 1) + !!x;

	// Total 13 operations.
	return x;
}

