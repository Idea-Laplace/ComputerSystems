#include <stdio.h>

int main(void) {
	printf("Size of:\n");
	printf("char: %ld\n", sizeof (char));
	printf("short: %ld\n", sizeof (short));
	printf("int: %ld\n", sizeof (int));
	printf("long: %ld\n", sizeof (long));
	printf("long long: %ld\n", sizeof (long long));
	printf("pointer: %ld\n", sizeof(void *));

	return 0;
}
