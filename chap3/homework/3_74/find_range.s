.globl find_range

find_range:
	vxorps	%xmm0, %xmm0, %xmm1
	ucomiss	%xmm1, %xmm0
	movl	$0, %edi
	movl	$1, %esi
	movl	$2, %edx
	movl	$3, %ecx
	movl	%edx, %eax
	cmovb	%edi, %eax
	cmove	%esi, %eax
	cmovp	%ecx, %eax
	ret
