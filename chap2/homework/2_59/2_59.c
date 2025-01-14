/*
   Write a C expression that will yield a word consisting of the least
   significant byte of x and the remaining bytes fo y. For operands
   x = 0x89abcdef and y = 0x76543210, this would give 0x765432ef.
*/

#include <stdio.h>

typedef unsigned char *byte_pointer;

int byte_remix(int x, int y);

int main(void) {
	int x = 0x89abcdef;
	int y = 0x76543210;
	int z = byte_remix(x, y);

	printf("x = %x\n", x);
	printf("y = %x\n", y);
	printf("z = %x\n", z);

	return 0;
}

int byte_remix(int x, int y) {
	return (x & 0xff) | (y & ~0xff);
}
		

