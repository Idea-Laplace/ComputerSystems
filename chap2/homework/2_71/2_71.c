#include <stdio.h>


typedef unsigned packed_t;

/*
	A: What's wrong with the this function?
	ans) This code didn't take into account that
	the sign bit extension is needed when mounting 
	2's complement number onto a larger 2's comlement datatype.
*/
int fool_xbyte(packed_t word, int bytenum) {
	return (word >> (bytenum << 3)) & 0xff;
}

// B, The (int) casting is essential to use arithmetic right shifts,
// to implement the assumption that the given machine uses arithemetic shifts.
int corrected_xbyte(packed_t word, int bytenum) {
	return (int) word << ((3 - bytenum) << 3) >> 24; 
}


int main(void) {
	// 8bits -> 32bits
	// 0x56  -> 0x56
	// 0x78  -> 0x78
	// 0x90  -> -0x70, 0xffffff90
	// 0xab  -> -0x55, 0xffffffab
	unsigned x = 0x567890ab;
	signed char test[4] = {0xab, 0x90, 0x78, 0x56};

	printf("x: %x\n", x);
	for (int i = 0; i < 4; i++) {
		printf("%d          : %x\n", i, corrected_xbyte(x, i));
		printf("Signed byte: %x\n", test[i]);
	}

	return 0;
}

