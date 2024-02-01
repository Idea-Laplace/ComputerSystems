#include <stdio.h>
#include <endian.h>

typedef unsigned char *UNIT;

unsigned replace_byte(unsigned x, int i, unsigned char b);

int main(void) {
	int x = 0x12345678;
	unsigned char b = 0xab;

	printf("%x\n", replace_byte(x, 2, b));
	printf("%x\n", replace_byte(x, 0, b));
	return 0;
}

unsigned replace_byte(unsigned x, int i, unsigned char b) {
	unsigned replace = x;
	UNIT p = &replace;
	if (BYTE_ORDER == LITTLE_ENDIAN) {
		*(p + i) = b;
		return replace;
	}

	if (BYTE_ORDER == BIG_ENDIAN) {
		*(p + sizeof(x) - 1 - i) = b;
		return replace;
	}
}

