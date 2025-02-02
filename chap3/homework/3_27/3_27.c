/*
   Problem 3.27
   Write goto code for a function called fibonacci to print
   fibonacci numbers using a while loop. Apply the guarded-do
   transformation.
*/
#include <stdio.h>
#include <stdlib.h>
#define DEFAULT 5


int fibonacci(int n) {
	int lead = 1, lag = 0, temp;

	int i = 2;
	// Guarded do strategy.
	if (n < 2) goto done;
loop:
	// Body statements
	temp = lead;
	lead += lag;
	lag = temp;

	// Update
	i++;
	// Test statement
	if (i <= n) goto loop;
done:
	return lead;
}


int main(int argc, char **argv) {
	int n = argc > 1 ? atoi(argv[1]) : DEFAULT;
	printf("Fibonacci number: %d\n", fibonacci(n));
	return 0;
}
