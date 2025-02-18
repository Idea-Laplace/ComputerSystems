#include <stdio.h>

#define INTERNAL static
typedef unsigned char *byte_pointer;

INTERNAL void show_bytes(byte_pointer start, size_t len) {
	for (int i = 0; i < len; i++)
		printf(" %.2x", start[i]);
	printf("\n");
}

void show_int(int x) {
	show_bytes((byte_pointer) &x, sizeof(int));
}

void show_float(float x) {
	show_bytes((byte_pointer) &x, sizeof(float));
}

void show_double(double x) {
	show_bytes((byte_pointer) &x, sizeof(double));
}

void show_pointer(void *x) {
	show_bytes((byte_pointer) &x, sizeof(void *));
}
