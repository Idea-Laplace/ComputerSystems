.globl find_range

find_range:
	vxorps	%xmm0, %xmm0, %xmm1
	ucomiss	%xmm0, %xmm1
	jp	.L4
	ja	.L1
	je	.L2
	jb	.L3
.Done:
	rep; ret
.L1:
	movl	$0, %eax
	jmp .Done
.L2:
	movl	$1, %eax
	jmp .Done
.L3:
	movl	$2, %eax
	jmp .Done
.L4:
	movl	$3, %eax
	jmp .Done
