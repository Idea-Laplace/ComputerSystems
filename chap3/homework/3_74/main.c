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
