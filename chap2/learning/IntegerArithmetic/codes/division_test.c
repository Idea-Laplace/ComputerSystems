#include <stdio.h>


int main(void) {
	printf("8/3 = %d * 3 + %d\n", 8 / 3, 8 % 3);
	printf("8/(-3) = %d * (-3) + %d\n", 8 / -3, 8 % -3);
	printf("(-8)/3 = %d * 3 + %d\n", -8 / 3, -8 % 3);
	printf("(-8)/(-3) = %d * (-3) + %d\n", -8 / -3, -8 % -3);

	return 0;
}
