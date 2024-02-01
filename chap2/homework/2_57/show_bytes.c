#include <stdio.h>
#include "show_bytes.h"

#define INTERNAL static
typedef unsigned char *UNIT;

INTERNAL void show_bytes(UNIT start, size_t len) {
	for (size_t i = 0; i < len; i++)
		printf(" %.2x", start[i]);
	printf("\n");
}

void show_short(short x) {
	show_bytes((UNIT) &x, sizeof(short));
}

void show_int(int x) {
	show_bytes((UNIT) &x, sizeof(int));
}

void show_long(long x) {
	show_bytes((UNIT) &x, sizeof(long));
}

void show_float(float x) {
	show_bytes((UNIT) &x, sizeof(float));
}

void show_double(double x) {
	show_bytes((UNIT) &x, sizeof(double));
}

void show_pointer(void *x) {
	show_bytes((UNIT) &x, sizeof(void *));
}
