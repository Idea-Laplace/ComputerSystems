	.file	"3_58.c"
	.text
	.p2align 4
	.globl	decode2_as
	.type	decode2_as, @function
decode2_as:
.LFB0:
	.cfi_startproc
	endbr64
	subq	%rdx, %rsi
	imulq	%rsi, %rdi
	movq	%rsi, %rax
	salq	$63, %rax
	sarq	$63, %rax
	xorq	%rdi, %rax
	ret
	.cfi_endproc
.LFE0:
	.size	decode2_as, .-decode2_as
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
