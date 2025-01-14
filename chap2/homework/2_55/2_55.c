/*
   Try running ths code for show_bytes for different sampe values
*/


#include <stdio.h>
#define INTERNAL static

typedef unsigned char *byte_pointer;

INTERNAL void show_bytes(byte_pointer p, size_t len);

void show_short(short s);
void show_int(int i);
void show_long(long l);
void show_float(float f);
void show_double(double d);
void show_pointer(void *p);

int main(void) {
	int test = 0x125690ab;
	printf("Apparent form: %x\n", test);
	printf("Endian:");
	show_int(test);

	printf("Endian: Little endian.\n");
	return 0;
}

INTERNAL void show_bytes(byte_pointer p, size_t len) {
	for (int i = 0; i < len; i++)
		printf(" %x", (int)*(p + i));
	putchar('\n');
}

void show_short(short s) {
	show_bytes((byte_pointer) &s, sizeof(short));
}

void show_int(int i) {
	show_bytes((byte_pointer) &i, sizeof(int));
}

void show_long(long l) {
	show_bytes((byte_pointer) &l, sizeof(long));
}

void show_float(float f) {
	show_bytes((byte_pointer) &f, sizeof(float));
}

void show_double(double d) {
	show_bytes((byte_pointer) &d, sizeof(double));
}

void show_pointer(void *p) {
	show_bytes((byte_pointer) p, sizeof(void *));
}
