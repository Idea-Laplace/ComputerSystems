/*
   Write a procedure is_little_endian that will return 1 when compiled and run
   on a little-endian machine, and will return 0 when compiled and run on a big-
   endian machine. This program should run on any machine, regardless of its word
   size.
*/

#include <stdio.h>
#include <stdbool.h>

typedef unsigned char *byte_pointer;

bool is_little_endian(void);

int main(void) {
	char *endian = is_little_endian() ? "Little endian" : "Big endian";

	printf("%s\n", endian);

	return 0;
}


bool is_little_endian(void) {
	static const int test_endian = 0xff;
	byte_pointer p = (byte_pointer) &test_endian;

	return *p == 0xff;
}
