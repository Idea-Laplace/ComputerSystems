/*
   This is very low-quality code.
   It is intended to illustrate bad programming practice.
   See Practice Problem 3.46.
*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define LEN 3

char *get_line(void) {
	char buffer[LEN + 1];
	char *result;

	gets(buffer);
	result = malloc(strlen(buffer));
	strcpy(result, buffer);
	return result;
}
