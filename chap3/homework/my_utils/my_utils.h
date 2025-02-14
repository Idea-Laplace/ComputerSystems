#include <stdbool.h>

union context4bytes;
union context8bytes;

void set_unsigned(union context4bytes *, unsigned);
void set_float(union context4bytes *, float);
void set_int(union context4bytes *, int);
void set_unsignedlong(union context8bytes *, unsigned long);
void set_double(union context8bytes *, double);
void set_long(union context8bytes *, long); 

unsigned get_unsigned(union context4bytes *);
float get_float(union context4bytes *);
int get_int(union context4bytes *);
unsigned long get_unsignedlong(union context8bytes *);
double get_double(union context8bytes *);
long get_long(union context8bytes *);

void float_binary(float f);
void float_hex(float f);
void double_binary(double d);
void double_hex(double d);
void loop_control(bool *loop);
