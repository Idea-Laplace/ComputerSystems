short test_one(unsigned short x) {
	short val = 1;
	while (x != 0) {
		val ^= x;
		x >>= 1;
	}
	// Invert the the value, returns 0 when even parity else 1.
	return val ^ 1;
}


