#include <stdio.h>

// bis: bit setting
// bicL bit clearing

/*
   & 0 1  | 0 1  ^ 0 1  NAND 0 1  NOR 0 1  bis 0 1  bic 0 1
   0 0 0  0 0 1  0 0 1     0 1 1    0 1 0    0 0 1    0 0 0
   1 0 1  1 1 1  1 1 0     1 1 0    1 0 0    1 1 1    1 1 0
*/

int bis(int x, int m);
int bic(int x, int m);

int bool_or(int i, int j);
int bool_xor(int i, int j);

int main(void) {
	int i, j;
	i = 9;
	j = 7;

	printf("          x      m  \n");
	printf("Initial: %06b, %06b\n", i, j);
	printf("bis: %06b\n", bis(i, j));
	printf("bic: %06b\n", bic(i, j));
	printf("bool_or: %06b\n", bool_or(i, j));
	printf("bool_xor: %06b\n", bool_xor(i, j));

	return 0;
}

int bis(int x, int m) {
	return x | m;
}

int bic(int x, int m) {
	return x & ~m;
}

int bool_or(int i, int j) {
	return bis(i, j);
}

int bool_xor(int i, int j) {
	return bic(i, j) | bic(j, i);
}
