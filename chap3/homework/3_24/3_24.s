	.file	"3_24.c"
	.text
	.globl	loop_whle
	.type	loop_whle, @function
loop_whle:
.LFB0:
	.cfi_startproc
	endbr64
	movl	$0, %eax
	jmp	.L2
.L3:
	addl	%edi, %eax
	addl	%esi, %eax
	subl	$1, %edi
.L2:
	cmpw	%si, %di
	jg	.L3
	ret
	.cfi_endproc
.LFE0:
	.size	loop_whle, .-loop_whle
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
