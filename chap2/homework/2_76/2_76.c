#include <stdio.h>
#include <stdlib.h>  // malloc, calloc, realloc
#include <string.h>  // memset

#define TYPE unsigned
#define NMEMB 5
#define SIZE sizeof(TYPE)

void *my_calloc(size_t nmemb, size_t size);


int main(void) {
	void *p = my_calloc(NMEMB, SIZE);
	for (int i = 0; i < NMEMB; i++) {
		printf("%0*x ", (int) SIZE * 2, *((TYPE *)p + i));
	}
	printf("\n");
	free(p);
	return 0;
}


void *my_calloc(size_t nmemb, size_t size) {
	if (!nmemb || !size || (nmemb * size) / size != nmemb)
		return NULL;

	void *p = malloc(nmemb * size);
	memset(p, 0, nmemb * size);

	return p;
}

