#include <stdio.h>


int main(void) {
	signed short i;
	unsigned short u; 

	i = 0xffff;
	u = 0xffff;
	printf("Signe short 0xffff  : %016hb\n", i);
	printf("Unsigned short 0xffff: %016hb\n", u);
	printf("Sigend 0xffff>>2  : %016hb\n", i>>2);
	printf("Unsigned 0xffff>>2: %016hb\n", u>>2);
	printf("Signed   0xffff<<2: %016hb\n", i<<2);
	printf("Unsigned 0xffff<<2: %016hb\n", u<<2);
	

	return 0;
}


/*
   For right shift operation in C, it is implemented defined
   whether it is logical or arithmetic for signed types, so
   you should perform shift operation only on unsinged numbers.
*/

