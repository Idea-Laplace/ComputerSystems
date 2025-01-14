#include <stdio.h>

int main(void) {
	float f;
	double d;

	f = 1.0e20f;
	d = 1.0;

	printf("%d\n", (f + d) - f == d);
	printf("%f\n", f + d);
	return 0;
}


