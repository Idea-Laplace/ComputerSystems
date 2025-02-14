	.file	"3_54.c"
	.text
	.p2align 4
	.globl	funct2
	.type	funct2, @function
funct2:
.LFB0:
	.cfi_startproc
	endbr64
	pxor	%xmm2, %xmm2
	movapd	%xmm0, %xmm3
	pxor	%xmm0, %xmm0
	cvtsi2ssl	%edi, %xmm2
	mulss	%xmm1, %xmm2
	cvtss2sd	%xmm2, %xmm0
	pxor	%xmm2, %xmm2
	cvtsi2sdq	%rsi, %xmm2
	divsd	%xmm2, %xmm3
	subsd	%xmm3, %xmm0
	ret
	.cfi_endproc
.LFE0:
	.size	funct2, .-funct2
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
