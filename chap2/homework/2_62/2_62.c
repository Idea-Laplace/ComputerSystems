/*
   Write a function int_shifts_are_arithmetic() that yields 1 when run on
   a machine that uses arithmetic right shifts for data type int and yields
   0 otherwise. Your code shoud work on a machine with any word size. Test
   your code on several machines.
*/

#include <stdio.h>


int int_shifts_are_arithmetic(void);


int main(void) {
	printf("%s right shifts machine.\n",\
		   	int_shifts_are_arithmetic() ? "Arithmetic" : "Logical");
	return 0;
}


int int_shifts_are_arithmetic(void) {
	// If a given machine uses arithmetic right shifts, ~0 >> 1 equals to ~0 itself,
	return !((~0 >> 1) ^ ~0);
}
