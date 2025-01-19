/*
   Write code to implement the following function:

   // Return 1 when any odd bit of x equals 1; 0 otherwise.
   // Assume w = 32.

   int any_odd_one(unsigned x);

   Your function should follow the bit-level integer coding rules,
   except that you may assume that data type int has w=32 bits.
*/

#include <stdio.h>


int any_odd_one(unsigned x);


int main(void) {
	unsigned x1 = 0x55555555; // 0b01010101010101010101010101010101
	unsigned x2 = 0x55565555;

	printf("%x: %d\n", x1,  any_odd_one(x1));
	printf("%x: %d\n", x2,  any_odd_one(x2));
	return 0;
}

// case return 0: x =  0y0y0y0y0y0y0y0y0y0y0y0y0y0y0y0y
//                t =  10101010101010101010101010101010
// x & t == 0 iff all bits in odd position are 0.
int any_odd_one(unsigned x) {
	const unsigned t = 0xaaaaaaaa;
	return !!(x & t);
}

