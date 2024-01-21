#ifndef BYTE_REPR_H
#define BYTE_REPR_H

typedef unsigned char *byte_pointer;


void show_bytes(byte_pointer start, size_t len);

void show_int(int x);

void show_float(float x);

void show_pointer(void *x);

void type_selection(void);

#endif

