#include <stdio.h>
#define CASES 5

struct internal {
	char c;
	short sh;
	int i;
};

struct wrapper {
	struct internal a;
	struct internal b;
};

int main(void) {
	for (int i = 0; i < CASES; i++) {
		struct wrapper test;
		printf("Initial alignment test: %p\n", &test);

		printf("Interal A : %p\n", &test.a);
		printf("First element(char)	  : %p\n", &test.a.c);
		printf("Second element(short) : %p\n", &test.a.sh);
		printf("Third element(int)  : %p\n", &test.a.i);

		printf("Interal B  : %p\n", &test.b);
		printf("First element(char)	  : %p\n", &test.b.c);
		printf("Second element(short) : %p\n", &test.b.sh);
		printf("Third element(int)  : %p\n", &test.b.i);

		putchar('\n');
	}
	return 0;
}
