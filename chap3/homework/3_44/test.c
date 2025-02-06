#include <stdio.h>
#include <limits.h>

struct test {
	char ch;
	long l;
	short sh;
	int i;
};

int main(void) {
	struct test check = {15, LONG_MAX, 3555, INT_MAX};

	printf("Sizeof char: %lu\n", sizeof(char));
	printf("Sizeof short: %lu\n", sizeof(short));
	printf("Sizeof int: %lu\n", sizeof(int));
	printf("Sizeof long: %lu\n", sizeof(long));

	printf("Address: %p\n", &check);
	printf("ch offset: %#lx\n", (void *) &check.ch - (void *) &check);
	printf("l offset: %#lx\n", (void *) &check.l - (void *) &check);
	printf("sh offset: %#lx\n", (void *) &check.sh - (void *) &check);
	printf("i offset: %#lx\n", (void *) &check.i - (void *) &check);
	
	return 0;
}

