#include <assert.h>
#include <stdint.h>
#include <stdlib.h>

int foo(int *a0, int a1, int a2) {
    int a3, a4, a5, a6, a7, t1, t3;
    int *t4;
    int64_t tmp = (int64_t) a1 << 32;
    a5 = tmp >> 30;
    t4 = a5 >> 30;
    t4 = a0 + t4;
    t3 = *t4;
    a6 = a0;
    a7 = (int) a2;
    if (a1 >= a2) goto L7;
    t1 = a7 << 2;
    a5 = *a0 + t1;
    a4 = a7;
L6:
    a3 = a5;
    a2 = a6 + t1;
    a4 = a4 - 1;
    if (a3 <= t3) goto L5;
    a0 = &a2;
    a7 = a7 - 1;
    a2 = a3;
    a5 = *a0;
    t1 = a7 << 2;
L5:
    a5 = a5 - 4;
    if (a1 < a4) goto L6;
    t3 = *t4;
    a6 = a6 + t1;
    a5 = a6;
    a6 = t3;
    a0 = &a7;
    *t4 = a5;

    return *a0;
L7:
    t1 = a7 << 2;
    a6 = a6 + t1;
    a5 = a6;
    a6 = t3;
    a0 = &a2;
    *t4 = a5;

    return *a0;
}

main() {
    unsigned sz, i;
    int ret = scanf("%u", &sz);
    int *v = calloc(sz, sizeof(int));

    assert(ret == 1);


    for (i = 0; i < sz; ++i) {
        ret = scanf("%d", &v[i]);
    }
}
