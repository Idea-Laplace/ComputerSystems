#include <stdio.h>
#include <inttypes.h>

extern uint64_t pushtest(void);

int main(void) {
	uint64_t pt;
	pt = pushtest();
	printf("Pushtest result: %llu\n", pt);
	return 0;
}


