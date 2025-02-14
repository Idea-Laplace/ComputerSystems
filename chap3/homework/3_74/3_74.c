#include <stdio.h>
#include <assert.h>
#include <limits.h>
#include "../my_utils/my_utils.h"

typedef enum {NEG, ZERO, POS, OTHER} range_t;

range_t find_range(float f);

int main(void) {
	union context4bytes *context;
	unsigned u;
	float f;
	int expr;

	for (u = 0; u != UINT_MAX; u++) {
		set_unsigned(context, u);
		f = get_float(context);
		expr = (f == 0.0f) + 2*(f > 0.0f) + 3*(f != f);
		assert(find_range(f) == expr);
	}

	return 0;
}

range_t find_range(float f) {
	asm("vxorps	%%xmm0, %%xmm0, %%xmm1\n\t"
		"ucomiss	%%xmm1, %%xmm0\n\t"
		"movl	$2, %%eax\n\t"
		"movl	$0, %%edi\n\t"
		"movl	$1, %%esi\n\t"
		"movl	$3, %%edx\n\t"
		"cmovb	%%edi, %%eax\n\t"
		"cmove	%%esi, %%eax\n\t"
		"cmovp	%%edx, %%eax\n\t"
		:
		:
		: "%edi", "%esi", "%edx", "%eax");
}

