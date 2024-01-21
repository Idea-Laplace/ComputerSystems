#include <stdio.h>
#include "show_bytes.h"
#define FLUSH while (getchar() != '\n')

int main(void) {
	int reply;
	union {
		int i;
		float f;
		double r;
		void *p;
	} input;

	printf("------------------------\n");
	printf("| i: integer byte      |\n");
	printf("| f: float byte        |\n");
	printf("| r: double byte       |\n");
	printf("| p: pointer byte      |\n");
	printf("| q: quit              |\n");
	printf("------------------------\n");
	
	for (;;) {
		printf("Select mode you want(i/f/r/p/q): ");
		reply = getchar();
		FLUSH;


		switch (reply) {
			case 'i':
				printf("Enter an integer: ");
				scanf("%d", &input.i);
				FLUSH;
				printf("Bytes representation:\n");
				show_int(input.i);
				break;
			case 'f':
				printf("Enter a real(float) number: ");
				scanf("%f", &input.f);
				FLUSH;
				printf("Bytes representation:\n");
				show_float(input.f);
				break;
			case 'r':
				printf("Enter a real(double) number: ");
				scanf("%lf", &input.r);
				FLUSH;
				printf("Bytes representation:\n");
				show_double(input.r);
				break;
			case 'p':
				printf("This is the representation for the address of union 'input'.\n");
				printf("Bytes representation:\n");
				show_pointer((void *) &input);
				break;
			case 'q':
				printf("Process terminated.\n");
				return 0;
			default:
				printf("Invalid input, ignored.\n");
				break;
		}
	}
}


