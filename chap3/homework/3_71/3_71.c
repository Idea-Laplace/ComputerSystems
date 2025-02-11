#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define DEFAULT 50

void good_echo(void);

int main(void) {
	printf("This program implements good_echo function.\n");
	good_echo();
	return 0;
}

void good_echo(void) {
	size_t width = DEFAULT;
	char *buffer = malloc(width + 1);
	int cur_len = 0;

	if (buffer == NULL) {
		fprintf(stderr, "Error: Cannot allocate a block of memory for buffer.\n");
		exit(EXIT_FAILURE);
	}

	for (;;) {
		fgets(buffer + cur_len, width + 1 - cur_len, stdin);
		cur_len = strlen(buffer);

		if (feof(stdin) || buffer[cur_len - 1] == '\n')
			break;

		if (width > 2 * width) {
			fprintf(stderr, "Error: Input is too large, to allocate memory.\n");
			exit(EXIT_FAILURE);
		}

		width *= 2;
		buffer = realloc(buffer, width + 1);
		if (buffer == NULL) {
			fprintf(stderr, "Error: Cannot extend the buffer memory.\n");
			exit(EXIT_FAILURE);
		}
	}
	fputs(buffer, stdout);
}

