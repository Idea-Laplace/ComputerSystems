// lt: less than, ge: greater or equal.
int lt_count  = 0;
int ge_count  = 0;

// Normal C code.
int absdiff_se(int x, int y) {
	int result;
	if (x < y) {
		lt_count++;
		result = y - x;
	} else {
		ge_count++;
		result = x - y;
	}

	return result;
}

// Assembly-like flow.
int gotodiff_se(int x, int y) {
	int result;
	if (x >= y) goto x_ge_y;
	lt_count++;
	result = y - x;
	return result;

x_ge_y:
	ge_count++;
	result - x - y;
	return result;
}
