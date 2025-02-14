#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>

#define FLUSH while (getchar() != '\n')

union context4bytes {
	int i;
	unsigned u;
	float f;
};

union context8bytes {
	long l;
	unsigned long lu;
	double d;
	void *p;
};

void set_unsigned(union context4bytes *context, unsigned u) {
	context->u = u;
}

void set_float(union context4bytes *context, float f) {
	context->f = f;
}

void set_int(union context4bytes *context, int i) {
	context->i = i;
}

void set_unsignedlong(union context8bytes *context, unsigned long lu) {
	context->lu = lu;
}

void set_double(union context8bytes *context, double d) {
	context->d = d;
}

void set_long(union context8bytes *context, long l) {
	context->l = l;
}


unsigned get_unsigned(union context4bytes *context) {
	return context->u;
}

float get_float(union context4bytes *context) {
	return context->f;
}

int get_int(union context4bytes *context) {
	return context->i;
}

unsigned long get_unsignedlong(union context8bytes *context) {
	return context->lu;
}

double get_double(union context8bytes *context) {
	return context->d;
}

long get_long(union context8bytes *context) {
	return context->l;
}


void float_binary(float f) {
	union context4bytes context = {.f = f};
	printf("%#032b\n", context.u);
}

void float_hex(float f) {
	union context4bytes context = {.f = f};
	printf("%#08x\n", context.u);
}

void double_binary(double d) {
	union context8bytes context = {.d = d};
	printf("%#064lb\n", context.lu);
}

void double_hex(double d) {
	union context8bytes context = {.d = d};
	printf("%#016lx\n", context.lu);
}

void loop_control(bool *loop) {
	static int reply;
	do {
		printf("Loop this procedure?[y/n]: ");
		reply = toupper(getchar());
		FLUSH;

		switch (reply) {
		case 'N':
			*loop = false;
			printf("Procedure terminated.\n");
		case 'Y':
			break;
		default:
			printf("Invaild input, type y[Y] or n[N] on the first input character.\n");
		}
	} while (reply != 'Y' && reply != 'N');
}
