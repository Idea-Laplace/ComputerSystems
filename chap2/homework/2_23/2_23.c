#include <stdio.h>

/*
   Assume these functions are executed as a 32 bit program on a machine
   that uses two's complement arithmetic. Assume also that right shifts
   of signed values are performed arithmetically. while right shifts of 
   unsigned values are performed logically.
*/

/*
   The fun1 function extract the least significant byte value of unsigned form
   from 0 to 255.
   The fun2 function extract the least significant byte value of signed form
   from -128 to 127.
*/

int fun1(unsigned word) {
	return (int) ((word << 24) >> 24);
}

int fun2(unsigned word) {
	return (((int) word << 24) >> 24);
}


int main(void) {
	unsigned w1, w2, w3, w4;
	w1 = 0x00000076;
	w2 = 0x87654321;
	w3 = 0x000000c9;
	w4 = 0xedcba987;

	printf("%0x, %0x\n", fun1(w1), fun2(w1));
	printf("%0x, %0x\n", fun1(w2), fun2(w2));
	printf("%0x, %0x\n", fun1(w3), fun2(w3));
	printf("%0x, %0x\n", fun1(w4), fun2(w4));

	return 0;
}
