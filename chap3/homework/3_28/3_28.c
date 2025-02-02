#define TYPE short
#define INITIAL (sizeof(TYPE) << 3)

TYPE test_two(unsigned TYPE x) {
	TYPE val = 0;
	unsigned TYPE i;
	for (i = INITIAL; i != 0; i--) {
		// Gurantees val is even
		val <<= 1;
		// Bit pattern of x is inserted to val in reverse order.
		val |= x & 1;
		x >>= 1;
	}
	return val;
}


