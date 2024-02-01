#include <stdbool.h>
#include <stdio.h>

bool is_little_endian(void);

int main(void) {
	int test;
	test = is_little_endian();

	printf("%d\n", test);
	return 0;
}


