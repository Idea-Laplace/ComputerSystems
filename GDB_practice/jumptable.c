void switcher(long a, long b, long c, long *dest) {
	short val = 0;
	switch (a) {
	case 5:
		c = b & 0xf;
	case 0:
		val = c + 112;
		break;
	case 2: case 4:
		val = b + c + 4;
		break;
	default:
		val = b;
	}
	*dest = val;
}

