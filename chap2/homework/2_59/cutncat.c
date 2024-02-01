#include <stdio.h>
#include <endian.h>

typedef unsigned char *UNIT;

int cutncat(int x, int y) {
	int i = 0;
	UNIT p = &i, q;
	if (BYTE_ORDER == LITTLE_ENDIAN) {
		q = &x;
		*p = *q;

		q = &y;
		for (size_t k = 1; k < sizeof(q); k++)
			*(p + k) = *(q + k);
		return i;
	}

	if (BYTE_ORDER == BIG_ENDIAN) {
		q = &x;
		*p = *(q + sizeof(q) - 1);

		q = &y;
		for (size_t k = 0; k < sizeof(q) - 1; k++)
			*(p + k) = *(q + k);
		return i;
	}
}


int main(void) {
	int x = 0x89ABCDEF;
	int y = 0x76543210;

	printf("%x\n", cutncat(x, y));
	return 0;
}





		



