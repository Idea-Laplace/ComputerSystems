#include <stdio.h>
#include "show_bytes.h"

#define FLUSH while (getchar() != '\n')

int main(void) {
	union {
		int *i_pointer;
		float *f_pointer;
	} context;

	int input;

	printf("Enter an integer: ");
	scanf(" %d", &input);
	FLUSH;

	printf("%d represented with binary form: %b\n", input, input);

	
	context.i_pointer = &input;
	show_int(*context.i_pointer);
	printf("Interger context: %d\n", *context.i_pointer);

	context.f_pointer = (float *) &input;
	show_float(*context.f_pointer);
	printf("Float number context: %f\n", *context.f_pointer);

	return 0;
}






