#include <stdio.h>
#include <inttypes.h>


typedef unsigned __int128 uint128_t;

void store_uprod(uint128_t *dest, uint64_t x, uint64_t y);

int main(void) {
	uint128_t dest;
	uint64_t *p = &dest;
	store_uprod(&dest, 0xabcdef0987, 0x1234567890);
	printf("%0llx %0llx\n", *(p + 1), *p);

	return 0;
}


void store_uprod(uint128_t *dest, uint64_t x, uint64_t y) {
	*dest = x * (uint128_t) y;
}
