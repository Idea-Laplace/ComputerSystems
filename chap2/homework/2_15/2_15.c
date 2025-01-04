#include <stdio.h>
#include <stdbool.h>

bool is_same(int a, int b);

int main(void) {
	int a, b, c;
	a = b = 8192;
	c = 8193;

	is_same(a, b);
	is_same(a, c);

	printf("Logical version.\n");
	printf("%d == %d, %s.\n", a, b, (a==b) ? "True" : "False");
	printf("%d == %d, %s.\n", a, c, (a==c) ? "True" : "False");
	printf("!(a^b) version.\n");
	printf("%d == %d, %s.\n", a, b, (is_same(a, b)) ? "True" : "False");
	printf("%d == %d, %s.\n", a, c, (is_same(a, c)) ? "True" : "False");

	return 0;
}

bool is_same(int a, int b) {
	if (!(a^b))
		return true;
	else
		return false;
}
