void decode1(long *xp, long *yp, long *zp) {
	long x = *xp, y = *yp, z = *zp;

	*yp = x;
	*zp = y;
	*xp = z;

	return;
}
