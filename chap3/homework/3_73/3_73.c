#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>
#include <limits.h>

#define FLUSH while (getchar() != '\n')

typedef enum {NEG, ZERO, POS, OTHER} range_t;

range_t find_range(float x);
void loop_decision(bool *loop);

int main(void) {
	float f;

#ifndef DEBUG
	bool loop = true;
	while (loop) {
		printf("Enter a floating-point number(f*(f/f): ");
		scanf(" %g", &f);
		f = f * (f / f);
		printf("Your input is %g\n", f);
		FLUSH;

		printf("%d\n", find_range(f));
		loop_decision(&loop);
	}
#else
	union {
		unsigned int u;
		float f;
	} type_cvt;
	range_t test;

	for (type_cvt.u = 0; type_cvt.u != UINT_MAX; type_cvt.u++) {
		test = (type_cvt.f == 0.0f) + 2*(type_cvt.f > 0.0f) + 3*(type_cvt.f != type_cvt.f);
		if (!(find_range(type_cvt.f) == test)) {
			printf("%#b, %f\n", type_cvt.u, type_cvt.f);
			printf("%d, %d\n", find_range(type_cvt.f), test);
			printf("Exception occured.");
			return 0;
		}
	}
	printf("NO exception happend.\n");
#endif
	return 0;
}

void loop_decision(bool *loop) {
	int reply;
	do {
		printf("Loop this procedure?[y/n]: ");
		reply = toupper(getchar());
		FLUSH;

		switch (reply) {
		case 'Y': break;
		case 'N':
			*loop = false;
			printf("Procedure terminated.\n");
			break;
		default:
			printf("Invaild input, type y[Y] or n[N] on the first input character.\n");
		}
	} while (reply != 'Y' && reply != 'N');
}
