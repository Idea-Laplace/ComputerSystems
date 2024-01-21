#include <stdint.h>

// Intentional verbose code
int64_t mult2(int64_t, int64_t);
int64_t multstore(int64_t x, int64_t y, int64_t *dest) {
	int64_t t = mult2(x, y);
	*dest = t;
}


