/*
   Write C expressions that evaluate to 1 when the following conditions are
   true and to 0 when they are false. Assume x is of type int.

   A> Any bit of x equals 1.
   B> Any bit of x equals 0.
   C> Any bit in the least significant byte of x equals 1.
   D> Any bit in the most significant byte of x  equals 0.
*/

#include <stdio.h>
#include <limits.h>

#define LEN 4

int function_a(int x);
int function_b(int x);
int function_c(int x);
int function_d(int x);

int main(void) {
	int test_set[LEN] = {0, 1, -1, INT_MIN};

	for (int i = 0; i < LEN; i++) {
		printf("%0*b\n", (int) (sizeof(int) << 3), test_set[i]);
		printf("1 existence: %d\n", function_a(test_set[i]));
		printf("0 existence: %d\n", function_b(test_set[i]));
		printf("LSB 1 existence: %d\n", function_c(test_set[i]));
		printf("MSB 0 exsitence: %d\n", function_d(test_set[i]));
		putchar('\n');
	}

	return 0;
}

