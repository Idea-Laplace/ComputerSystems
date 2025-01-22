#include <stdio.h>
#include <assert.h>

unsigned f2u(float);
int float_le(float x, float y);

int main(void) {
	assert(!float_le(-1.f, -2.f));
	assert(float_le(1.f, 2.f));
	assert(float_le(-0.f, 0.f));
	assert(float_le(-1.f, 1.f));
	return 0;
}

unsigned f2u(float x) {
	unsigned *context;
	context = (unsigned *) &x;
	return *context;
}


int float_le(float x, float y) {
	unsigned ux = f2u(x);
	unsigned uy = f2u(y);
    /* Get the sign bit */
	unsigned sx = ux >> 31;
	unsigned sy = uy >> 31;

	/* Give an expression using only ux, uy, sx, and sy. */
	return sx && !sy || sx && sy && ux >= uy || !sx && !sy && uy >= ux;
}

