	.file	"3_57.c"
	.text
	.p2align 4
	.globl	funct3
	.type	funct3, @function
funct3:
.LFB0:
	.cfi_startproc
	endbr64
	vxorps	%xmm1, %xmm1, %xmm1
	vmovsd	%xmm0, %xmm0, %xmm3
	vmovss	(%rdx), %xmm0
	vcvtsi2ssq	%rsi, %xmm1, %xmm2
	vcvtsi2sdl	(%rdi), %xmm1, %xmm1
	vcomisd	%xmm1, %xmm3
	jbe	.L6
	vmulss	%xmm2, %xmm0, %xmm0
	vcvtss2sd	%xmm0, %xmm0, %xmm0
	ret
	.p2align 4,,10
	.p2align 3
.L6:
	vfmadd132ss	.LC0(%rip), %xmm2, %xmm0
	vcvtss2sd	%xmm0, %xmm0, %xmm0
	ret
	.cfi_endproc
.LFE0:
	.size	funct3, .-funct3
	.section	.rodata.cst4,"aM",@progbits,4
	.align 4
.LC0:
	.long	1073741824
	.ident	"GCC: (Ubuntu 13.3.0-6ubuntu2~24.04) 13.3.0"
	.section	.note.GNU-stack,"",@progbits
	.section	.note.gnu.property,"a"
	.align 8
	.long	1f - 0f
	.long	4f - 1f
	.long	5
0:
	.string	"GNU"
1:
	.align 8
	.long	0xc0000002
	.long	3f - 2f
2:
	.long	0x3
3:
	.align 8
4:
