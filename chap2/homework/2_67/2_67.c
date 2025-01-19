/*
	You are given the task of writing a procedure int_size_is_32() that
	yields 1 when run on a machine for which an int is 32 bits, and yields
	0 otherwise. You are not allowed to use the sizeof operator. Here is a
	first attempt:

	// The followig code does not run properly on some mahcines.
	int bad_int_size_is_32(void) {
		// Set most significant bit (msb) of 32-bit machine
		int set_msb = 1 << 31;
		// Shift past msb of 32-bit word.
		int beyond_msb = 1 << 32;

		// set_msb is nonzero when word size >= 32
		// beyond_msb is zero when word size <= 32

		return set_msb && !beyond_msb;
	}

	When compiled and run on a 32-bit SUN SPRAC, however, this procedure
	returns 0. The following compiler message gives us an indication of the
	problem:

	warning> left shift count >= width of type.

	A. In what way does our code fail to comply with the C standard?
	B. Modify the code to run properly on any machine for which data type int
	   is at least 32 bits.
	C. Modify the code to run properly on any machine for which data type int
	   is at least 16 bits.
*/

// A. The C standards does not define bit shift operation when the amount of shift 
//    lower than 0 or larger than or equal to the word size of the given data type.
//    The 'int beyond_msb = 1 << 32;' line is what evoke an undefined behavior.


#include <stdio.h>

int int_size_is_32_b(void);
int int_size_is_32_c(void);

int main(void) {
	printf("%d\n", int_size_is_32_b());
	printf("%d\n", int_size_is_32_c());
	return 0;
}


int int_size_is_32_b(void) {
	/* B. Modify the code to run properly on any machine for which data type int
	   is at least 32 bits. */
	int set_msb = 1 << 31;
	return !(set_msb << 1);
}

int int_size_is_32_c(void) {
	/* C. Modify the code to run properly on any machine for which data type int
	   is at least 16 bits. */

	int set_msb = 1 << 15;
	set_msb <<= 15;
	return (set_msb << 1) && !(set_msb << 2);
}

