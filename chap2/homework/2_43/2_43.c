/*
   In the following code, we have omitted the definitions of constants
   M and N.

#define M // Mystery number 1
#define N // Mystery number 2

int arith*int x, int y) {
	int result = 0;
	result = x * M + y / N;
	return result;
}

We complied this code for particular values of M and N. The compiler
optimized the multiplication and division using the methods we have
discussed. The following is a translation of the generated machine code
back into C:

// Translation of assembly code for arith.
int optimized_arith(int x, int y) {
	int t = x;
	x <<= 5;
	x -= t;
	if (y < 0)
		y += 7;
	y >>= 3;

	return x + y;
}

What are the value of M and N?
*/


// Answer: M = 31, (2^5 - 1)
//         N = 8, (2^3, 7 = 2^3 - 1)
