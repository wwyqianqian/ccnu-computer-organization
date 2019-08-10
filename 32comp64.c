#include <stdio.h>

long int sample (long int *xp, long int y) {
    long int t = *xp + y;
    *xp = t;
    return t;
}



// gcc-8 -O1 -S -m64 32comp64.c

/* 32
_sample:                                ## @sample
	.cfi_startproc
## %bb.0:
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset %ebp, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register %ebp
	movl	8(%ebp), %ecx
	movl	(%ecx), %eax
	addl	12(%ebp), %eax
	movl	%eax, (%ecx)
	popl	%ebp
	retl
	.cfi_endproc
*/


/* 64
_sample:
LFB1:
	movq	%rsi, %rax
	addq	(%rdi), %rax
	movq	%rax, (%rdi)
	ret
*/
