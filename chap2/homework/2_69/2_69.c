#include <stdio.h>
#include <stdlib.h>


unsigned rotate_left(unsigned x, int n);


int main(int argc, char **argv) {
	unsigned x = atoi(argv[1]);
	int n = atoi(argv[2]);
	
	printf("%08x\n", x);
	printf("%032b\n", x);
	printf("Rotation: %d\n", n);
	printf("Result: %08x\n", rotate_left(x, n));
	printf("Result: %032b\n", rotate_left(x, n));
	return 0;
}


unsigned rotate_left(unsigned x, int n) {
	unsigned w = sizeof(int) << 3;
	unsigned head = x << n;
	unsigned tail = x >> (w - n - 1);

	return head | (tail >> 1);
}
