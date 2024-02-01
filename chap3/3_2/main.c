// Intentionally unoptimized code.
#include <stdio.h>

void multstore(long, long, long *);

int main(void) {
	long ld;
	multstore(2, 3, &ld);
	printf("2 * 3 -> %ld\n", ld);
	return 0;
}


long mult2(long a, long b) {
	long s = a * b;
	return s;
}
