	.file	"3_38.c"
	.text
	.globl	add_element
	.type	add_element, @function
add_element:
.LFB0:
	.cfi_startproc
	endbr64
	leaq	0(,%rdi,8), %rdx
	subq	%rdi, %rdx
	addq	%rsi, %rdx
	leaq	(%rsi,%rsi,4), %rax
	addq	%rdi, %rax
	leaq	Q(%rip), %rcx
	movq	(%rcx,%rax,8), %rax
	leaq	P(%rip), %rcx
	addq	(%rcx,%rdx,8), %rax
	ret
	.cfi_endproc
.LFE0:
	.size	add_element, .-add_element
	.globl	Q
	.bss
	.align 32
	.type	Q, @object
	.size	Q, 280
Q:
	.zero	280
	.globl	P
	.align 32
	.type	P, @object
	.size	P, 280
P:
	.zero	280
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
