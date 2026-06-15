#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

typedef int (*cmp_t)(void const *lhs, void const *rhs);

int cmp(void const *lhs, void const *rhs) {
    if (lhs > rhs) return 1;

    return 0;
}

int selstep(void *parr, int eltsize, int numelts, int nsorted, cmp_t cmp) {
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

    selstep(arr, 1, sz, pos, cmp);

    free(arr);

    return 0;
}
