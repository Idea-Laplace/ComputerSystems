/*
   For the where data type int has 32-bit, devise a version of tmult_ok
   that uses the 64-bit precision of data type int64_t, without using
   division.
*/

#include <stdio.h>
#include <stdint.h>

int tmult_ok(int x, int y) {
	// () cast operator take precedence over *.
	int64_t p = (int64_t) x * y;
	// (int) p will be truncated, and be recasted to int64_t by left p.
	return p == (int) p;
}

