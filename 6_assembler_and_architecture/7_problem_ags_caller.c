int caller(int x, int y, int z) {
    int eax;
    int rsp;
    int ebx;
    int r12d;
    int r13d;
    int rbp;
    int bl;
        rsp = rsp - 8;
        r12d = 1;

        if (y == 0) goto L1;

        eax = x;
        ebx = y;
        r13d = z;
        z = 0;
        z = eax % r13d; eax = eax / r13d;
        rbp = z;
        r12d = 1;
        goto L5;
    L3:
        x = ebp;
        z = r13d;
        y = ebp;
        callee(x, y, z);
        ebp = eax;
        ebx = ebx >> 1;
    L4:
        if (ebx == 0) goto L1;
    L5:
        if (bl % 2 == 0) goto L3;
        z = r13d;
        y = ebp;
        x = r12d;
        callee(x, y, z);
        r12d = eax;
        ebx -= 1;
        goto L4;
    L1:
        eax = r12d;
        return eax;
}
