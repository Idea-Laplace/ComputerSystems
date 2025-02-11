#define CNT 7

#ifdef CHAR
#define TYPE signed char
#elif defined(SHORT)
#define TYPE short
#elif defined(INT)
#define TYPE int
#elif defined(long)
#define TYPE long
#else
#define TYPE long
#endif

typedef TYPE signed_t;


typedef struct {
	signed_t idx;
	long x[4];
} a_struct;

typedef struct {
	int first;
	a_struct a[CNT];
	int last;
} b_struct;

void test(long i, b_struct *bp) {
	int n = bp->first + bp->last;
	a_struct *ap = &bp->a[i];
	ap->x[ap->idx] = n;
}

