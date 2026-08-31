int foo() {
    a5 = a1 << 32;
    srlit4 = a5 >> 30;
    t4 = a0 + t4;
    t3 = *t4;
    a6 = a0;
    a7 = (int32_t) a2;
    if (a1 >= a2) goto L7;
    t1 = a7 << 2;
    a5 = a0 + t1;
    a4 = a7;
.L6:
    a3 = *a5;
    a2 = a6 + t1;
    a4 = a4 - 1;
    if (a3 <= t3) goto L5;
    a0 = *a2;
    a7 = a7 - 1;
    *a2 = a3;
    *a5 = a0;
    t1 = a7 << 2;
.L5:
    a5 = a5 - 4;
    if (a1 < a4) goto L6;
    t3 = *t4;
    a6 = a6 + t1;
    a5 = *a6;
    *a6 = t3;
    a0 = (int32_t) a7;
    *t4 = a5;
    return a0;
.L7:
    t1 = a7 << 2
    a6 = a6 + t1
    a5 = *a6
    *a6 = t3
    a0 = a2
    *t4 = a5
    return a0

}
