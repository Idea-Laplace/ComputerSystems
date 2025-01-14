#define SRC signed char
#define DEST int

typedef SRC src_t;
typedef DEST dest_t;

int main(void) {
	src_t *sp;
	dest_t *dp;

	*dp = (dest_t) *sp;

	return 0;
}
