	.file	"3_41.c"
	.text
	.globl	st_init
	.type	st_init, @function
st_init:
.LFB0:
	.cfi_startproc
	endbr64
	movzwl	8(%rdi), %eax
	movw	%ax, 10(%rdi)
	leaq	10(%rdi), %rax
	movq	%rax, (%rdi)
	movq	%rdi, 16(%rdi)
	ret
	.cfi_endproc
.LFE0:
	.size	st_init, .-st_init
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
