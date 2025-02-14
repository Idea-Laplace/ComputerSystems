#include <stdio.h>
#define WIDTH 7

char *gets_vulnerable2overflow(char *buffer) {
	int ch;
	char *dest = buffer;
	while ((ch = getchar()) != '\n' && ch != EOF)
		*dest++ = ch;

	if (ch == EOF && dest == buffer)
		return NULL;

	*dest++ = '\0';
	return buffer;
}

void echo(void) {
	char buffer[WIDTH + 1];
	printf("Function echo activated: ");
	gets_vulnerable2overflow(buffer);
	puts(buffer);
}

