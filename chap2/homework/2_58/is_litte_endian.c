#include <stdbool.h>


bool is_little_endian(void) {
	unsigned char *p, ch;
	short hd;
	ch = 1;
	hd = 1;
	p = &ch;
	return *p == ch;
}
