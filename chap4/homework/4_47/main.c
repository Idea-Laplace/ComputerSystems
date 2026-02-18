#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 20
#define SCALE ((N)*5)

void bubble_a(long *data, long count);
void bubble_p(long *data, long count);

void print_arr(long *data, long count);

int main(void) {
    srand(time(NULL));
    long arr_a[N], arr_p[N], i;

    for (i = 0; i < N; i++) {
        arr_a[i] = rand() % SCALE;
        arr_p[i] = arr_a[i];
    }
    
    printf("arr_a: ");
    print_arr(arr_a, N);
    printf("arr_p: ");
    print_arr(arr_p, N);
    printf("\n");

    bubble_a(arr_a, N);
    bubble_p(arr_p, N);
    printf("Bubble sort applied.\n");

    printf("arr_a: ");
    print_arr(arr_a, N);
    printf("arr_p: ");
    print_arr(arr_p, N);
        
    printf("Program terminataed.\n");

    return 0;
}

void print_arr(long *data, long count) {
    printf("[");
    for (long i = 0; i < count; i++) {
        printf("%ld", data[i]);
        printf(i == count - 1 ? "" : " ");
    }
    printf("]\n");
}
