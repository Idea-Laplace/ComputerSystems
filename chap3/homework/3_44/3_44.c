#include <stdio.h>

struct P1 {short i; int c; int *j; short *d;};
struct P2 {int i[2]; char c[8]; short s[4]; long *j;};
struct P3 {long w[2]; int *c[2];};
struct P4 {char w[16]; char *c[2];};
struct P5 {struct P4 a[2]; struct P1 t;};

struct wrapper {
	struct P1 test1;
	struct P2 test2;
	struct P3 test3;
	struct P4 test4;
	struct P5 test5;
};

int main(void) {
	struct wrapper test;


	printf("P1: %lu\n", (void *) &test.test1 - (void *) &test);
	printf("%lu\n", (void *) &test.test1.i - (void *) &test.test1);
	printf("%lu\n", (void *) &test.test1.c - (void *) &test.test1);
	printf("%lu\n", (void *) &test.test1.j - (void *) &test.test1);
	printf("%lu\n", (void *) &test.test1.d - (void *) &test.test1);
	printf("\n");

	printf("P2: %lu\n", (void *) &test.test2 - (void *) &test);
	printf("%lu\n", (void *) &test.test2.i - (void *) &test.test2);
	printf("%lu\n", (void *) &test.test2.c - (void *) &test.test2);
	printf("%lu\n", (void *) &test.test2.s - (void *) &test.test2);
	printf("%lu\n", (void *) &test.test2.j - (void *) &test.test2);
	printf("\n");

	printf("P3: %lu\n", (void *) &test.test3 - (void *) &test);
	printf("%lu\n", (void *) &test.test3.w - (void *) &test.test3);
	printf("%lu\n", (void *) &test.test3.c - (void *) &test.test3);
	printf("\n");

	printf("P4: %lu\n", (void *) &test.test4 - (void *) &test);
	printf("%lu\n", (void *) &test.test4.w - (void *) &test.test4);
	printf("%lu\n", (void *) &test.test4.c - (void *) &test.test4);
	printf("\n");

	printf("P5: %lu\n", (void *) &test.test5 - (void *) &test);
	printf("%lu\n", (void *) &test.test5.a - (void *) &test.test5);
	printf("%lu\n", (void *) &test.test5.t - (void *) &test.test5);
	printf("\n");

	printf("Total size of test: %lu\n", sizeof(test));

	return 0;
}
