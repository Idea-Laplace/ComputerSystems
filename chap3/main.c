// Intentionally unoptimized code.
#include <stdio.h>
#include <stdint.h>

void multstore(int64_t, int64_t, int64_t *);

int main(void) {
	int64_t ld;
	multstore(2, 3, &ld);
	printf("2 * 3 -> %ld\n", ld);
	return 0;
}


int64_t mult2(int64_t a, int64_t b) {
	int64_t s = a * b;
	return s;
}
