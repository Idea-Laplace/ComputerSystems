#include <stdio.h>
#include <stdlib.h>
#include "byte_repr.h"

#define FLUSH while (getchar() != '\n')

void show_bytes(byte_pointer start, size_t len) {
	int i;
	for (i = 0; i < len; i++)
		printf(" %.2x", *(start + i));
	printf("\n");
}

void show_int(int x) {
	show_bytes((byte_pointer) &x, sizeof(int));
}

void show_float(float x) {
	show_bytes((byte_pointer) &x, sizeof(float));
}

void show_pointer(void *x) {
	show_bytes((byte_pointer) &x, sizeof(void *));
}

void type_selection(void) {
	union {int i; float f; void *p;} type;
	static char ch;
	static _Bool valid_input;

	printf("Enter datatype(int(i)/float(f)/pointer(p)): ");
	ch = getchar();
	FLUSH;

	for (;;) {
		switch (ch) {
			case 'i':
				printf("Enter an integer: ");
				valid_input = scanf("%d", &type.i);
				FLUSH;
				if (!valid_input) {
					printf("Invalid input, ignored.\n");
					continue;
				}
				show_int(type.i);
				break;
			case 'f':
				printf("Enter a float number: ");
				valid_input = scanf("%f", &type.f);
				FLUSH;
				if (!valid_input) {
					printf("Invalid input, ignored.\n");
					continue;
				}
				show_float(type.f);
				break;
			case 'p':
				type.p = malloc(1);
				show_pointer(type.p);
				break;
			default:
				printf("Invalid input, ignored.\n");
				break;
		}
		break;
	}
}
				
				
		

