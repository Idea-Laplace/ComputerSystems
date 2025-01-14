/*
   Suppose we number the bytes in a w-bit word from 0(LS) to w/8 - 1(MS).
   Write code for the following C finction, which will return an unsigned
   value in which byte i of argument x has been replaced by b:

unsigned replace_byte(unsigned x, int i, unsigned char b);

   Here are some example showing how the function should work:

   replace_byte(0x12345678, 2, 0xab) -> 0x1234ab78
   replace_byte(0x12345678, 0, 0xab) -> 0xab345678
*/

#include <stdio.h>
#include <limits.h>

unsigned replace_byte(unsigned x, int i, unsigned char b);

int main(void) {
	unsigned test_x = 0x12345678;
	unsigned char test_b = 0xab;

	printf("x: %x\n", test_x);
	printf("b: %x\n", test_b);

	printf("0th byte replacement: %x\n", replace_byte(test_x, 0, test_b));
	printf("1st byte replacement: %x\n", replace_byte(test_x, 1, test_b));
	printf("2nd byte replacement: %x\n", replace_byte(test_x, 2, test_b));
	printf("3rd byte replacement: %x\n", replace_byte(test_x, 3, test_b));
	
	return 0;
}

unsigned replace_byte(unsigned x, int i, unsigned char b) {
	const int byte = 8;

	if (i < 0 || i > sizeof(unsigned) - 1) {
		printf("Invalid byte position, ignored.\n");
		return INT_MIN;
	}

	// Solution: you can just use i << 3 instead of defining the byte as 8.
	unsigned clear_byte = ~(0xffU << byte * i);  // or << (i << 3)
	unsigned repalce_byte = (unsigned) b << byte * i; // or << (i << 3)

	return (x & clear_byte) | repalce_byte;
}


