	.file	"3_56.c"
	.text
	.globl	simpefun
	.type	simpefun, @function
simpefun:
.LFB0:
	.cfi_startproc
	endbr64
	xorpd	.LC0(%rip), %xmm0
	ret
	.cfi_endproc
.LFE0:
	.size	simpefun, .-simpefun
	.section	.rodata.cst16,"aM",@progbits,16
	.align 16
.LC0:
	.long	0
	.long	-2147483648
	.long	0
	.long	0
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
