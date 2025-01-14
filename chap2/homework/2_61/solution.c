// Returns 1 if any bit of x equals 1 else 0.
int function_a(int x) {
	// !!x returns 1 if x is nonzero else 0.
	return !!x;
}

// Returns 1 if any bit of x equals 0 else 0.
int function_b(int x) {
	// ~(-1) is 0.
	return !!~x;
}

// Returns 1 if any bit in the LSB of x equals 1 else 0.
int function_c(int x) {
	// Tests whether x & 0xff is nonzero.
	return !!(x & 0xff);
}

// Returns 1 if any bit in the MSB of x equals 0 else 0.
int function_d(int x) {
	// Bit shift operators are left-associative.
	// Shifts the MSB of x to the LSB.
	// Unsigned casting needs due to logical shifts.
	// w-1 << 3 is a conventional expression for the byte-shifting.
	x = (unsigned) x >> ((sizeof(int) - 1) << 3);
	
	// Tests x & 0xff is not 0xff.
	// & takes precedence over ^.
	return !!((x & 0xff) ^ 0xff);
}



