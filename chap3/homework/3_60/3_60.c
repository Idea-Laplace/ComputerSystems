// Extracts bit values for every n th bit in x.
// For safety in using shift, mask = mask << (n % 64) would be safer.
// I think there would have been some statements that guarantee n is
// betwwn 0 and 63.
long loop(long x, long n) {
	long result = 0;
	long mask;
	for (mask = 1; mask != 0; mask <<= n) {
		result |= x & mask;
	}
	return result;
}
