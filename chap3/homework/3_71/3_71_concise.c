#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 50

void good_echo(void);

int main(void) {
	printf("This program implements good_echo function.\n");
	good_echo();
	return 0;
}

void good_echo(void) {
	char buffer[BUFFER_SIZE + 1];

	while (!feof(stdin) && buffer[strlen(buffer) - 1] != '\n') {
		fgets(buffer, sizeof(buffer), stdin);
		fputs(buffer, stdout);
	}
}

