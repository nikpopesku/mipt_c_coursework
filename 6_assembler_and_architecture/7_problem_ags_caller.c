int caller() {
        rsp = rsp - 8;
        r12d = 1;

        if (esi == 0) goto L1;

        eax = edi;
        ebx = esi;
        r13d = edx;
        edx = 0;
        edx = eax % r13d; eax = eax / r13d;
        rbp = rdx;
        r12d = 1;
        goto L5;
    L3:
        edi = ebp;
        edx = r13d;
        esi = ebp;
        callee(edi, esi, edx);
        ebp = eax
        ebx = ebx >> 1
    L4:
        if (ebx == 0) goto L1;
    L5:
        if (bl % 2 == 0) goto L3;
        edx = r13d;
        esi = ebp;
        edi = r12d;
        callee(edi, esi, edx);
        r12d = eax;
        ebx -= 1;
        goto L4
    L1:
        eax = r12d;
        rsp += 8;
        return eax;
}
