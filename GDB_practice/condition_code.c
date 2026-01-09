#include <stdio.h>

unsigned add_flag(unsigned a, unsigned b) {
	return a + b;
}

unsigned sub_flag(unsigned a, unsigned b) {
	return a - b;
}

int main(void) {
// Check through gdb, disp $eflags.
	unsigned a, b, c, d;
	a = add_flag(1, 1);
	b = add_flag(-1, 2);
	c = sub_flag(2, 1);
	d = sub_flag(1, 2);

	printf("%d ", a);
	printf("%d ", b);
	printf("%d ", c);
	printf("%d\n", d);

	return 0;
}
