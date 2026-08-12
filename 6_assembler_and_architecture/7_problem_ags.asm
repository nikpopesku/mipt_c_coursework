.text
.globl  caller
.type caller, @function
caller:
    push  r13          ; push to stack for callee func
    push  r12          ; push to stack for callee func
    push  rbp          ; push to stack for callee func
    push  rbx          ; push to stack for callee func
    sub rsp, 8         ;rsp = rsp - 8
    mov r12d, 1        ;r12d = 1
    test  esi, esi     ; esi & esi
    je  .L1            ;if (esi == 0) goto L1
    mov eax, edi       ;eax = edi
    mov ebx, esi       ;ebx = esi
    mov r13d, edx      ;r13d = edx
    mov edx, 0         ;edx = 0
    div r13d           ; eax = eax / r13d; edx = eax % r13d
    mov rbp, rdx       ; rbp = rdx
    mov r12d, 1        ; r12d = 1
    jmp .L5            ; goto L5
.L3:
    mov edi, ebp       ;edi = ebp
    mov edx, r13d      ;edx = r13d
    mov esi, ebp       ;esi = ebp
    call  callee       ;callee
    mov ebp, eax       ;ebp = eax
    shr ebx            ;ebx = ebx >> 1
.L4:
    test  ebx, ebx     ;ebx & ebx
    je  .L1            ; if (ebx == 0) goto L1
.L5:
    test  bl, 1        ; bl & 1
    je  .L3            ; if (bl % 2 == 0) goto L3
    mov edx, r13d      ; edx = r13d
    mov esi, ebp       ; esi = ebp
    mov edi, r12d      ; edi = r12d
    call  callee       ; callee()
    mov r12d, eax      ; r12d = eax
    sub ebx, 1         ; ebx -= 1
    jmp .L4            ; goto L4
.L1:
    mov eax, r12d       ; eax = r12d
    add rsp, 8          ; rsp += 8
    pop rbx             ; pop from stack
    pop rbp             ; pop from stack
    pop r12             ; pop from stack
    pop r13             ; pop from stack
    ret                 ; return eax