void switcher(long a, long b, long c, long *dest) {
	long val;
	switch(a) {
	// .L7
	case 5:
		c = b ^ 0xf;
		// Fall through
	case 0:
		val = c + 112;
		break;
	// .L5
	case 2:
	case 7:
		val = (b + c) << 2;
		break;
	case 4:
		val = a;
		break;
	// .L2
	default:
		val = b;
	}
	// .L6
	*dest = val;
}


/*
// a in %rdi, b in %rsi, c in %rdx, dest in %rcx
switcher:
	cmpq	$7, %rdi
	ja		.L2
	jmp		*.L4(, %rdi, 8)
	.section		.rodata
.L7:
	xorq	$15, %rsi
	movq	%rsi, %rdx
.L3:
	leaq	112(%rdx), %rdi
	jmp		.L6
.L5
	leaq	(%rdx, %rsi), %rdi
	salq	$2, %rdi
	jmp		.L6
.L2
	movq	%rsi, %rdi
.L6
	movq	%rdi, (%rcx)
	ret

.L4
	.quad	.L3
	.quad	.L2
	.quad	.L5
	.quad	.L2
	.quad	.L6
	.quad	.L7
	.quad	.L2
	.quad	.L5
.L2 is the default case, So the .L5 is the only label that duplicates.
so the case 2 and case 7 should be in the consecutive cases.
.L7 fall through to .L3, hence .L7 comes first and .L3 follows right after .L7.
Now the only left label is .L6, fits into the last case.
*/
