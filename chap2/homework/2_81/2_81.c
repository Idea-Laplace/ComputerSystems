#include <stdio.h>
#include <stdlib.h>


int main(int argc, char **argv) {
	int k = argc > 1 ? atoi(argv[1]) : 7;
	int j = argc > 2 ? atoi(argv[2]) : 10;

	int w = sizeof(unsigned) << 3;
	unsigned A, B;

	A = (~0) << (k - !!k) << !!k;

	B = ~A << (j - !!j) << !!j;

	printf("A: %0*b\n", (int) sizeof(unsigned) << 3,  A);
	printf("B: %0*b\n", (int) sizeof(unsigned) << 3,  B);
	
	return 0;
}



