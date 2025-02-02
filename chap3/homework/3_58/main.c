#include <stdio.h>
#include <assert.h>
#include <limits.h>

#define RANGE 0x7ff

long decode2(long x, long y, long z);
long decode2_as(long x, long y, long z);

int main(void) {
	for (long x = 0; x < RANGE; x++)
		for (long y = 0; y < RANGE; y++)
			for (long z = 0; z < RANGE; z++)
				assert(decode2(x, y, z) == decode2_as(x, y, z));
	printf("Test finished.\n");
	return 0;
}
