/*
   Write a function with the following prototype:

   // Determines whether arguments can by added without overflow.
   int uadd_ok(unsigned x, unsigned y);

   This function should return 1 if x and y can be added without causing overflow.
*/


#include <stdio.h>


int uadd_ok(unsigned x, unsigned y);


int main(void) {
	unsigned x = 2000000000U;
	unsigned y = 2100000000U;
	unsigned z = 2200000000U;

	printf("uadd_ok(x, y): %d\n", uadd_ok(x, y));
	printf("uadd_ok(y, z): %d\n", uadd_ok(y, z));
	printf("uadd_ok(z, x): %d\n", uadd_ok(z, x));

	return 0;
}

int uadd_ok(unsigned x, unsigned y) {
	return x + y > x;
}


