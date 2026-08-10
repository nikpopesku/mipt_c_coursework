	.file	"start.c"
	.intel_syntax noprefix
	.text
	.p2align 4
	.globl	"start"
	.type	"start", @function
"start":
.LFB0:
	.cfi_startproc
	cmp	edi, 1
	jbe	.L5
	cmp	edi, 3
	jbe	.L6
	test	dil, 1
	je	.L5
	cmp	edi, 24
	jbe	.L6
	mov	ecx, 5
	jmp	.L7
	.p2align 5
	.p2align 4,,10
	.p2align 3
.L16:
	add	ecx, 2
	mov	eax, ecx
	imul	eax, ecx
	cmp	edi, eax
	jb	.L6
.L7:
	mov	eax, edi
	xor	edx, edx
	div	ecx
	test	edx, edx
	jne	.L16
.L5:
	xor	eax, eax
	ret
	.p2align 4,,10
	.p2align 3
.L6:
	mov	eax, 1
	ret
	.cfi_endproc
.LFE0:
	.size	"start", .-"start"
	.ident	"GCC: (GNU) 16.1.1 20260728"
	.section	.note.GNU-stack,"",@progbits
