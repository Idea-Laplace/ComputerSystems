long decode2(long x, long y, long z) {
	x *= y - z;
	return (y - z) % 2 == 0 ? x : ~x;
}
