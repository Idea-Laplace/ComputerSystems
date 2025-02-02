	.file	"3_21.c"
	.text
	.p2align 4
	.globl	test
	.type	test, @function
test:
.LFB0:
	.cfi_startproc
	endbr64
	testw	%di, %di
	js	.L7
	cmpw	$9, %si
	jle	.L8
	movswl	%di, %eax
	movswl	%si, %esi
	cltd
	idivl	%esi
.L1:
	ret
	.p2align 4,,10
	.p2align 3
.L8:
	leal	12(%rsi), %eax
	ret
	.p2align 4,,10
	.p2align 3
.L7:
	movl	%esi, %eax
	orl	%edi, %eax
	cmpw	%di, %si
	jle	.L1
	movl	%esi, %eax
	imull	%edi, %eax
	ret
	.cfi_endproc
.LFE0:
	.size	test, .-test
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
