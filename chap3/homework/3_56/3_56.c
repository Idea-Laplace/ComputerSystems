#ifdef A
#define EXPR(x) ((x) ? (x) : -(x))
#elif defined(B)
#define EXPR(x) 0.0
#elif defined(C)
#define EXPR(x) (-(x))
#else
#define EXPR(x) ((x) ? (x) : -(x))
#endif

double simpefun(double x) {
	return EXPR(x);
}

