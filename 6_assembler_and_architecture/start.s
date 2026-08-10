	.intel_syntax noprefix
	.text
	.p2align 4
	.globl	"start"
	.type	"start", @function
"start":
	cmp	edi, 1
	jbe	.composite
	cmp	edi, 3
	jbe	.prime
	test	dil, 1
	je	.composite
	cmp	edi, 8
	jbe	.prime
	mov	ecx, 3
	jmp	.L7
.loop:
	add	ecx, 2
	mov	eax, ecx
	imul	eax, ecx
	cmp	edi, eax
	jb	.prime
.L7:
	mov	eax, edi
	xor	edx, edx
	div	ecx
	test	edx, edx
	jne	.loop
.composite:
	xor	eax, eax
	ret
.prime:
	mov	eax, 1
	ret
