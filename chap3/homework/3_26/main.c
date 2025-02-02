#include <stdio.h>


short test_one(unsigned short x);


int main(void) {
	unsigned short x, y, z;
	x = 0b0;
	y = 0b1;
	z = 0b1101;

	printf("%hb: %s parity.\n", x, test_one(x) ? "odd" : "even");
	printf("%hb: %s parity.\n", y, test_one(y) ? "odd" : "even");
	printf("%hb: %s parity.\n", z, test_one(z) ? "odd" : "even");

	return 0;
}
