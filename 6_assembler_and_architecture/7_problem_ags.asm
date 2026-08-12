.text
.globl  caller
.type caller, @function
caller:
    push  r13
    push  r12
    push  rbp
    push  rbx
    sub rsp, 8         ;rsp = rsp - 8
    mov r12d, 1        ;r12d = 1
    test  esi, esi     ; esi & esi
    je  .L1            ;if (esi == 0) goto L1
    mov eax, edi       ;eax = edi
    mov ebx, esi       ;ebx = esi
    mov r13d, edx      ;r13d = edx
    mov edx, 0         ;edx = 0
    div r13d           ; eax = eax / r13d
    mov rbp, rdx       ; rbp = rdx
    mov r12d, 1        ; r12d = 1
    jmp .L5            ; goto L5
.L3:
    mov edi, ebp       ;edi = ebp
    mov edx, r13d      ;edx = r13d
    mov esi, ebp       ;edi = ebp
    call  callee       ;callee
    mov ebp, eax       ;ebp = eax
    shr ebx            ; ???
.L4:
    test  ebx, ebx     ;ebx & ebx
    je  .L1            ; if (ebx == 0) goto L1
.L5:
    test  bl, 1        ; bl & 1
    je  .L3            ; if (bl % 2 == 1) goto L3
    mov edx, r13d      ; edx = r13d
    mov esi, ebp       ; edi = ebp
    mov edi, r12d      ; edi = r12d
    call  callee       ; callee()
    mov r12d, eax      ; r12d = eax
    sub ebx, 1         ; ebx -= 1
    jmp .L4            ; goto L4
.L1:
    mov eax, r12d       ; eax = r12d
    add rsp, 8          ; rsp += 8
    pop rbx             ; pop from stack probably
    pop rbp             ; pop from stack probably
    pop r12             ; pop from stack probably
    pop r13             ; pop from stack probably
    ret                 ; return eax (probably)