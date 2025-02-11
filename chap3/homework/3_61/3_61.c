long cread_alt(long *xp) {
	// 'Safe' address created.
	static long when_xp_null = 0;

	// Guarantees that the address in 'result' is always valid.
	return *(xp ? xp : &when_xp_null);
}



