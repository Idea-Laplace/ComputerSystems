#include <stdio.h>

long scale(long x, long y, long z) {
	long t = x + 4 * y + 12 * z;
	return t;
}

int main(void) {
	int i;
	i = scale(1, 2, 3);
	printf("%d\n", i);
	return 0;
}
