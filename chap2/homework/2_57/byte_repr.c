#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include "byte_repr.h"
#include "show_bytes.h"

#define FLUSH while (getchar() != '\n')


bool type_selection(void) {
	union {short s; int i; long l; float f; double d; void *p;} type;
	static char ch;
	static bool valid_input;

	printf("Enter datatype(short(s)/int(i)/float(f)/long(l)/double(d)/pointer(p)/quit(q)): ");
	ch = getchar();
	FLUSH;

	switch (ch) {
		case 's':
			printf("Enter an integer: ");
			valid_input = scanf("%hd", &type.s);
			FLUSH;
			if (!valid_input) {
				printf("Invalid input, ignored.\n");
				return true;
			}
			show_short(type.s);
			break;
		case 'i':
			printf("Enter an integer: ");
			valid_input = scanf("%d", &type.i);
			FLUSH;
			if (!valid_input) {
				printf("Invalid input, ignored.\n");
				return true;
			}
			show_int(type.i);
			break;
		case 'l':
			printf("Enter an integer: ");
			valid_input = scanf("%ld", &type.l);
			FLUSH;
			if (!valid_input) {
				printf("Invalid input, ignored.\n");
				return true;
			}
			show_long(type.l);
			break;
		case 'f':
			printf("Enter a float number: ");
			valid_input = scanf("%f", &type.f);
			FLUSH;
			if (!valid_input) {
				printf("Invalid input, ignored.\n");
				return true;
			}
			show_float(type.f);
			break;
		case 'd':
			printf("Enter a float number: ");
			valid_input = scanf("%lf", &type.d);
			FLUSH;
			if (!valid_input) {
				printf("Invalid input, ignored.\n");
				return true;
			}
			show_double(type.d);
			break;
		case 'p':
			type.p = malloc(1);
			if (type.p == NULL) {
				printf("Error: cannot allocate memory for type.p\n");
				return true;
				break;
			}
			show_pointer(type.p);
			free(type.p);
			break;
		case 'q':
			printf("Process terminated.\n");
			return false;
		default:
			printf("Invalid input, ignored.\n");
			break;
	}
	return true;
}
