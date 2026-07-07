#include <assert.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef int (*cmp_t)(void const *lhs, void const *rhs);

int cmp(void const *lhs, void const *rhs) {
    const int a = *((int const *) lhs);
    const int b = *((int const *) rhs);

    if (a < b) return 1;

    return 0;
}

int selstep(void *parr, int eltsize, int numelts, int nsorted, cmp_t cmp) {
    const char *lhs;
    char *cur;
    char *a;
    char *b;
    char temp[eltsize];
    int new_pos;
    int found;
    int i;

    lhs = (char *)parr + (nsorted > 0 ? (nsorted - 1) * eltsize : 0);
    new_pos = nsorted;
    found = 0;

    for (i = nsorted; i < numelts; ++i) {
        cur = (char *)parr + i * eltsize;
        if (nsorted > 0 && cmp(cur, lhs) == 1)
            continue;
        if (!found || cmp(cur, (char *)parr + new_pos * eltsize) == 1) {
            new_pos = i;
            found = 1;
        }
    }

    if (found && new_pos != nsorted) {
        a = (char *)parr + nsorted * eltsize;
        b = (char *)parr + new_pos * eltsize;
        memcpy(temp, a, eltsize);
        memcpy(a, b, eltsize);
        memcpy(b, temp, eltsize);
    }

    return 0;
}

int main() {
    int sz;
    int res = scanf("%d", &sz);
    assert(res == 1);

    int *arr = calloc(sz, sizeof(int));
    for (int i = 0; i < sz; ++i) {
        scanf("%d", &arr[i]);
    }

    int pos;
    res = scanf("%d", &pos);
    assert(res == 1);

    for (int i = 0; i < sz; ++i) {
        printf("%d ", arr[i]);
    }

    selstep(arr, sizeof(int), sz, pos, cmp);

    free(arr);

    return 0;
}
