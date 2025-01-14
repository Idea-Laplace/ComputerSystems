/*
   Write a function div16 that returns value x/16 for integer
   argument x. Your function should not use division, modulus,
   multiplication, ant conditionals(if or ?:), any comparison
   operators(<, >, or ==, etc) or any loops. You may assume
   that tat type int is 32 bit long and uses a two's complement
   representation, and that right hifts shifts are performed ari-
   -thmetically.
*/

int div16(int x) {
	// bias will be 1 if the sign bit(MSB) is 1 else 0
	int bias = (unsigned) x >> sizeof(int) - 1; // word_size - 1.
	// (1 << 4) - 1 = 0b111 or (0 << 4) - 0 = 0b0.
	bias = (bias << 4) - bias;

	return (x + bias) >> 4;
}

int div16_book_solution(int x) {
	// x >> 31 would be 111....1111 if the sign bit were 1 else 0,
	// which causes (x >> 31) & 0b1111 to be 0b1111 if x is negative else 0.
	int bias = (x >> sizeof(int) - 1) & 0xf;

	return (x + bias) >> 4;
}
