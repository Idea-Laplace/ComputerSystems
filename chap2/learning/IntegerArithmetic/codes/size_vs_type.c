/* 
   This code show that, when converting from short to unsigned int,
   the program first changes the size and then the type.
   (unsigned) sx is actually (unsigend) (int) sx,
   not (unsigned) (unsigned short) sx, which would evaluate
   53191.
*/
#include <stdio.h>
#include <endian.h>

typedef unsigned char *byte_pointer;

void show_bytes(byte_pointer p, size_t word);

int main(void) {
	short sx = -12345;
	unsigned uy = sx;

	printf("uy = %u:\t", uy);
	show_bytes((byte_pointer) &uy, sizeof(unsigned));
	return 0;
}

void show_bytes(byte_pointer p, size_t word) {
	if (__BYTE_ORDER == LITTLE_ENDIAN) {
		for (int i = word - 1; i >= 0; i--)
			printf(" %x", *(p + i));
		putchar('\n');
	}

	else {
		for (int i = 0; i <word; i++)
			printf(" %x", *(p + i));
		putchar('\n');
	}
}
