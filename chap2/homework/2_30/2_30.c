/*
   Write a function with the following prototype:
   // Determines whether arguments cna be added without overflow
   int tadd_ok(int x, int y);

   This function should return 1 if arguments x and y can be added
   without causing overflow.
*/

#include <stdio.h>

int tadd_ok(int x, int y) {
	int s = x + y;
	return !(x > 0 && y > 0 && s <= 0) &&\
		!(x < 0 && y < 0 && s >= 0);
	
}
