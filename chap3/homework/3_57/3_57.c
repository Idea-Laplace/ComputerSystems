double funct3(int *ap, double b, long c, float *dp) {
	int a = *ap;
	float d = *dp;
	return b > a ? c * d : c + 2*d;
}

