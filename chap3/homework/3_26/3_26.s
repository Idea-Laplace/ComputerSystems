	.file	"3_26.c"
	.text
	.globl	test_one
	.type	test_one, @function
test_one:
.LFB0:
	.cfi_startproc
	endbr64
	movl	%edi, %edx
	testw	%di, %di
	je	.L4
	movl	$1, %eax
.L3:
	xorl	%edx, %eax
	shrw	%dx
	jne	.L3
.L2:
	xorl	$1, %eax
	ret
.L4:
	movl	$1, %eax
	jmp	.L2
	.cfi_endproc
.LFE0:
	.size	test_one, .-test_one
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
