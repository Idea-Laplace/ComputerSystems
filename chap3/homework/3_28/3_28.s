	.file	"3_28.c"
	.text
	.globl	test_two
	.type	test_two, @function
test_two:
.LFB0:
	.cfi_startproc
	endbr64
	movl	$16, %edx
	movl	$0, %eax
.L2:
	addl	%eax, %eax
	movl	%edi, %ecx
	andl	$1, %ecx
	orl	%ecx, %eax
	shrw	%di
	subw	$1, %dx
	jne	.L2
	ret
	.cfi_endproc
.LFE0:
	.size	test_two, .-test_two
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
