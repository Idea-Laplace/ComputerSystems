#include <stdio.h>
#include <stdlib.h>


int lower_one_mask(int n);


int main(int argc, char **argv) {
	printf("%d mask: %0*b\n", atoi(argv[1]), (int) (sizeof(int) * 8),\
							(unsigned) lower_one_mask(atoi(argv[1])));
	return 0;
}

int lower_one_mask(int n) {
	int mask = (1 << (n - 1)) - 1;
	return (mask << 1) + 1;
}

