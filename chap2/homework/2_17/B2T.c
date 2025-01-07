#include <stdio.h>
#define N 16

int binary2comlement(char *expr, size_t w);
int binary2unsigned(char *expr, size_t w);

int main(void) {
	char *bit4[N] = {"0000", "0001", "0010", "0011",\
		 			 "0100", "0101", "0110", "0111",\
					 "1000", "1001", "1010", "1011",\
					 "1100", "1101", "1110", "1111"};

	for (int i = 0; i < N; i++) {
		printf("%s, complement: %d, unsigned: %d\n",\
			   	bit4[i], binary2comlement(bit4[i], 4),\
				binary2unsigned(bit4[i], 4));
	}

	return 0;
						
}

int binary2comlement(char *expr, size_t w) {
	int sign, bit;
	int result = 0;
	for (int i = 0; i < w; i++) {
		bit = (expr[i] == '1') ? 1 : 0;
		sign = (i == 0) ? -1 : 1;
		result *= 2;
		result += sign * bit;
	}

	return result;
}

int binary2unsigned(char *expr, size_t w) {
	int bit;
	int result = 0;
	for (int i = 0; i < w; i++) {
		bit = (expr[i] == '1') ? 1 : 0;
		result *= 2;
		result += bit;
	}

	return result;
}

