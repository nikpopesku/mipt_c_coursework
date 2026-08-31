#include <assert.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

int foo(int *a0, int a1, int a2) {
    int a3, a4, a7, t1, t3, off, swp;
    long long tmp;
    int *a5, *a6, *pa2, *t4;

    tmp = (long long) a1 << 32;
    off = tmp >> 30;
    t4 = (int *) ((char *) a0 + off);
    t3 = *t4;
    a6 = a0;
    a7 = (int) a2;
    if (a1 >= a2) goto L7;
    t1 = a7 << 2;
    a5 = (int *) ((char *) a0 + t1);
    a4 = a7;
L6:
    a3 = *a5;
    pa2 = (int *) ((char *) a6 + t1);
    a4 = a4 - 1;
    if (a3 <= t3) goto L5;
    swp = *pa2;
    a7 = a7 - 1;
    *pa2 = a3;
    *a5 = swp;
    t1 = a7 << 2;
L5:
    a5 = (int *) ((char *) a5 - 4);
    if (a1 < a4) goto L6;
    t3 = *t4;
    a6 = (int *) ((char *) a6 + t1);
    swp = *a6;
    *a6 = t3;
    *t4 = swp;

    return a7;
L7:
    t1 = a7 << 2;
    a6 = (int *) ((char *) a6 + t1);
    swp = *a6;
    *a6 = t3;
    *t4 = swp;

    return a2;
}

int main() {
    unsigned sz, i;
    int ret = scanf("%u", &sz);
    int *v = calloc(sz, sizeof(int));

    assert(ret == 1);


    for (i = 0; i < sz; ++i) {
        ret = scanf("%d", &v[i]);
    }

    printf("%d\n", foo(v, 0, sz - 1));
}
