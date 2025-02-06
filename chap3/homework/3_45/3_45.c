#include <stdio.h>

struct rec_opt{
	int g;
	float b;
	long e;
	double f;
	int *a;
	char *h;
	short d;
	char c;
};

struct rec{
	int *a;
	float b;
	char c;
	short d;
	long e;
	double f;
	int g;
	char *h;
};

struct {
	struct rec_opt rec_opt;
	struct rec rec;

} wrapper;

int main(void) {
	printf("Size of rec_opt: %lu\n", sizeof(struct rec_opt));
	printf("Size of rec_opt in wrapper: %lu\n", sizeof(wrapper.rec_opt));
	printf("Size of rec: %lu\n", sizeof(struct rec));
	printf("Size of rec in wrapper: %lu\n", sizeof(wrapper.rec));
	printf("Size of wrapper: %lu\n", sizeof(wrapper));


	printf("Offsets of rec.opt:\n");
	printf("g: %lu\n", (void *) &wrapper.rec_opt.g - (void *) &wrapper.rec_opt);
	printf("b: %lu\n", (void *) &wrapper.rec_opt.b - (void *) &wrapper.rec_opt);
	printf("e: %lu\n", (void *) &wrapper.rec_opt.e - (void *) &wrapper.rec_opt);
	printf("f: %lu\n", (void *) &wrapper.rec_opt.f - (void *) &wrapper.rec_opt);
	printf("a: %lu\n", (void *) &wrapper.rec_opt.a - (void *) &wrapper.rec_opt);
	printf("h: %lu\n", (void *) &wrapper.rec_opt.h - (void *) &wrapper.rec_opt);
	printf("d: %lu\n", (void *) &wrapper.rec_opt.d - (void *) &wrapper.rec_opt);
	printf("c: %lu\n", (void *) &wrapper.rec_opt.c - (void *) &wrapper.rec_opt);

	printf("Offsets of rec:\n");
	printf("a: %lu\n", (void *) &wrapper.rec.a - (void *) &wrapper.rec);
	printf("b: %lu\n", (void *) &wrapper.rec.b - (void *) &wrapper.rec);
	printf("c: %lu\n", (void *) &wrapper.rec.c - (void *) &wrapper.rec);
	printf("d: %lu\n", (void *) &wrapper.rec.d - (void *) &wrapper.rec);
	printf("e: %lu\n", (void *) &wrapper.rec.e - (void *) &wrapper.rec);
	printf("f: %lu\n", (void *) &wrapper.rec.f - (void *) &wrapper.rec);
	printf("g: %lu\n", (void *) &wrapper.rec.g - (void *) &wrapper.rec);
	printf("h: %lu\n", (void *) &wrapper.rec.h - (void *) &wrapper.rec);
	return 0;
}
