	.file	"Original.c"
	.text
	.globl	fun_b
	.type	fun_b, @function
fun_b:
.LFB0:
	.cfi_startproc
	endbr64
	movl	$64, %edx
	movl	$0, %eax
	jmp	.L2
.L3:
	addq	%rax, %rax
	movq	%rdi, %rcx
	andl	$1, %ecx
	orq	%rcx, %rax
	shrq	%rdi
	subq	$1, %rdx
.L2:
	testq	%rdx, %rdx
	jne	.L3
	ret
	.cfi_endproc
.LFE0:
	.size	fun_b, .-fun_b
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
