/* Write code to implement the following function:
   // Return 1 when x contians an odd number of 1s; 0 otherwise.
   // Assume w = 32;
   int odd_ones(unsigned x);

   Your function should follow the bit-level integer coding rules
   except that you may that data type int has 32 bits.
   Your code should contain a total of at most 12 arithmetic,
   bitwise, and logical operations.
*/

#include <stdio.h>
#include <limits.h>


int odd_ones(unsigned x);


int main(void) {
	unsigned x1 = 0xaaaaaaaa; // 16 ones.
	unsigned x2 = 0xaaaabaaa; // 17 ones/
	unsigned x3 = 0;
	unsigned x4 = 1;

	printf("%0*b: %s\n", 32, x1, odd_ones(x1) ? "odd ones" : "even ones");
	printf("%0*b: %s\n", 32, x2, odd_ones(x2) ? "odd ones" : "even ones");
	printf("%0*b: %s\n", 32, x3, odd_ones(x3) ? "odd ones" : "even ones");
	printf("%0*b: %s\n", 32, x4, odd_ones(x4) ? "odd ones" : "even ones");
	return 0;
}


int odd_ones(unsigned x) {
	/*
	   If xk is either 0 or 1, then
	   x1 ^ x2 ^ ... ^ xn = 1 if there are odd ones xk else 0.
	*/

	// 2 operations.
	x ^= x >> 16;  // [xxxx xxxx xxxx xxxx], Least significant 16 bits.

	// 2 operations.
	x ^= x >> 8; // [xxxx xxxx], Least significant 8 bits.

	// 2 operations.
	x ^= x >> 4; // [xxxx], Least significant 8 bits.

	// 2 operations.
	x ^= x >> 2; // [xx], Least significant 2 bits.

	// 2 operations.
	x ^= x >> 1; // [x], the LSB.

	// 1 operation.
	// Clear all the other preceding bits. [abcd....efgh x] --> [0000...0000 x]
	// Total 2 * 5 + 1 = 11 bit-related operations.
	x &= 0x1;

	return x;
}
