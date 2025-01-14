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
	short test_short = 0x1234;
	int test_int = 0x125690ab;
	long test_long = 0x1234567890abcdL;
	float test_float = 3.14f;
	double test_double = 3.14;

	printf("%hx\n", test_short);
	printf("%x\n", test_int);
	printf("%lx\n", test_long);
	printf("%f\n", test_float);
	printf("%f\n", test_double);
	printf("%p\n", &test_int);

	show_short(test_short);
	show_int(test_int);
	show_long(test_long);
	show_float(test_float);
	show_double(test_double);
	show_pointer((void *) &test_int);

	printf("Endian: Little endian.\n");
	return 0;
}

INTERNAL void show_bytes(byte_pointer p, size_t len) {
	for (int i = 0; i < len; i++)
		printf(" %.2x", *(p + i));
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
