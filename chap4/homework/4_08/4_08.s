.text
.globl poptest
poptest:
	movq	%rsp, %rsi
	pushq	%rdi
	popq	%rsp
	movq	%rsp, %rax
	movq	%rsi, %rsp
	ret
