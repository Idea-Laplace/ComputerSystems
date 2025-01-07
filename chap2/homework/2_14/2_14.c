#include <stdio.h>

int main(void) {
	int a = 0x55;
	int b = 0x46;

	// 0x55 = 0b01010101
	// 0x46 = 0b01000110

	printf("a&b: %02x\n",  (a&b)); // 0b0100 0100, 0x44
	printf("a|b: %02x\n",  (a|b)); // 0b0101 0111, 0x57
	printf("~a|~b: %02hx\n", (~a|~b)); // 0b1011 1011 0xBB , one's complement for a&b
	printf("a&!b: %02x\n", (a&!b)); // 0x00
	printf("a&&b: %02x\n", (a&&b)); // 0x01
	printf("a||b: %02x\n", (a||b)); // 0x01
	printf("!a||!b: %02x\n", (!a||!b)); // 0x00, which is 0 || 0. 
	printf("a&&~b: %02x\n", (a&&~b)); //  0x01, which is 1 && 1.

	return 0;
}
