#define N 16

typedef int fix_matrix[N][N];

void fix_set_diag(fix_matrix A, int val) {
	int *base = &A[0][0];
	long index = 0;
	long stop_index = N * (N + 1);

	do {
		*(base + index) = val;
		index += N + 1;
	} while (index != stop_index);
}




