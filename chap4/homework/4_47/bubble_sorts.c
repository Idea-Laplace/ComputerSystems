/* Bubble sort: Array version */
void bubble_a(long *data, long count) {
    long i, last;
    for (last = count - 1; last > 0; last--) {
        for (i = 0; i < last; i++)
            if (data[i+1] < data[i]) {
                /* Swap adjacent elements */
                long t = data[i+1];
                data[i+1] = data[i];
                data[i] = t;
            }
    }
}

/* Bubble sort: Pointer version */
void bubble_p(long *data, long count) {
    if (count <= 1) return;
    long *head, *tail;
    for (tail = data + count - 1; tail - data > 0; tail--) {
        for (head = data; tail - head > 0; head++)
            if (*(head+1) < *head) {
                /* Swap adjacent elements */
                long t = *(head+1);
                *(head+1) = *head;
                *head = t;
            }
    }
}
