int caller() {
        rsp = rsp - 8;
        r12d = 1;

        if (esi == 0) goto L1;

        eax = edi;
        ebx = esi;
        r13d = edx;
        edx = 0;
        eax = eax / r13d; edx = eax % r13d;
        rbp = rdx;
        r12d = 1;
        goto L5;
    L3:
        edi = ebp
        edx = r13d
        esi = ebp
        callee()
        ebp = eax
        ebx = ebx >> 1
    L4:
        if (ebx == 0) goto L1;
    L5:
        if (bl % 2 == 0) goto L3;
        mov edx, r13d      ; edx = r13d
        mov esi, ebp       ; esi = ebp
        mov edi, r12d      ; edi = r12d
        call  callee       ; callee()
        mov r12d, eax      ; r12d = eax
        sub ebx, 1         ; ebx -= 1
        goto L4
    L1:
        eax = r12d;
        rsp += 8;
        return eax;
}
