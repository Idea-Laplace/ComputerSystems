#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>

#define DEFAULT 14


int32_t factorial32_goto(int32_t);
int64_t factorial64_goto(int64_t);


int main(int argc, char **argv) {
	int32_t n = argc > 1 ? atoi(argv[1]) : DEFAULT;
	int32_t factorial32bit;
	int64_t factorial64bit;

	factorial32bit = factorial32_goto(n);
	factorial64bit = factorial64_goto((int64_t) n);

	printf("%d! = %d\n", n, factorial32bit);
	printf("%d! = %ld\n", n, factorial64bit);

	return 0;
}

int32_t factorial32_goto(int32_t n) {
	int32_t fact = 1;
loop:
	fact *= n;
	n -= 1;
	if (n > 1) goto loop;

	return fact;
}

int64_t factorial64_goto(int64_t n) {
	int64_t fact = 1;
loop:
	fact *= n;
	n -= 1;
	if (n > 1) goto loop;

	return fact;
}
