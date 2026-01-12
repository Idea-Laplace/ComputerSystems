#include <stdio.h>
#include <inttypes.h>

extern uint64_t poptest(uint64_t);

int main(void) {
	uint64_t val;
	val = poptest(0xabcd);
	printf("Poptest result: %#llx\n", val);
	return 0;
}
