	.file	"prime.c"
	.intel_syntax noprefix
	.text
	.globl	"prime"
	.type	"prime", @function
"prime":
.LFB0:
	.cfi_startproc
	push	rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	mov	rbp, rsp
	.cfi_def_cfa_register 6
	mov	DWORD PTR -20[rbp], edi
	cmp	DWORD PTR -20[rbp], 1
	jg	.L2
	mov	eax, 0
	jmp	.L3
.L2:
	cmp	DWORD PTR -20[rbp], 3
	jg	.L4
	mov	eax, 1
	jmp	.L3
.L4:
	mov	eax, DWORD PTR -20[rbp]
	and	eax, 1
	test	eax, eax
	jne	.L5
	mov	eax, 0
	jmp	.L3
.L5:
	mov	DWORD PTR -4[rbp], 5
	jmp	.L6
.L8:
	mov	eax, DWORD PTR -20[rbp]
	cdq
	idiv	DWORD PTR -4[rbp]
	mov	eax, edx
	test	eax, eax
	jne	.L7
	mov	eax, 0
	jmp	.L3
.L7:
	add	DWORD PTR -4[rbp], 2
.L6:
	mov	eax, DWORD PTR -4[rbp]
	imul	eax, eax
	cmp	DWORD PTR -20[rbp], eax
	jge	.L8
	mov	eax, 1
.L3:
	pop	rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE0:
	.size	"prime", .-"prime"
	.ident	"GCC: (GNU) 16.1.1 20260728"
	.section	.note.GNU-stack,"",@progbits
