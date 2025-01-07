#include <stdio.h>

int main(void) {
	char ch1, ch2;
	short sh1, sh2;
	int i1, i2;
	long long ll1, ll2;
	ch1 = ch2 = 97;
	sh1 = sh2 = 8000;
	i1 = i2 = 27182818;
	ll1 = ll2 = 314159265358979LL;

	printf("%0*x, %0*x, %0*x, %0*llx\n", 2, ch1, 4, sh1, 8, i1, 16, ll1);

	ch1 = ch1 & (char) 0xff;
	sh1 = sh1 & (short) 0xff;
	i1 = i1 & (int) 0xff;
	ll1 = ll1 & (long long) 0xff;

	printf("%0*x, %0*x, %0*x, %0*llx\n", 2, ch1, 4, sh1, 8, i1, 16, ll1);

	ch1 = ch2;
	sh1 = sh2;
	i1 = i2;
	ll1 = ll2;

	ch1 = (char) (ch1 ^ ~0xff);
	sh1 = (short) (sh1 ^ ~0xff);
	i1 = (int) (i1 ^ ~0xff);
	ll1 = (long long) (ll1 ^ ~0xff);

	printf("%0*x, %0*x, %0*x, %0*llx\n", 2, ch1, 4, sh1, 8, i1, 16, ll1);

	ch1 = ch2;
	sh1 = sh2;
	i1 = i2;
	ll1 = ll2;

	ch1 = ch1 | (char) 0xff;
	sh1 = sh1 | (short) 0xff;
	i1 = i1 | (int) 0xff;
	ll1 = ll1 | (long long) 0xff;

	printf("%0*x, %0*x, %0*x, %0*llx\n", 2, ch1, 4, sh1, 8, i1, 16, ll1);

	return 0;
}



