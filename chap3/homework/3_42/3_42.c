#include <stdlib.h>

struct ACE {
	short v;
	struct ACE *p;
};

/* Returns the accumulated multiplication value
   in a linked list from the given start node. */
short test(struct ACE *ptr) {
	short val = 1;
	while (ptr != NULL) {
		val *= ptr->v;
		ptr = ptr->p;
	}
	return val;
}






