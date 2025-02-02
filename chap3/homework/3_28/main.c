#include <stdio.h>

unsigned short test_two(unsigned short);

int main(void) {
	unsigned short x = 0b1101001100111101;

	printf("%hb\n", x);
	printf("%hb\n", test_two(x));
	return 0;
}

