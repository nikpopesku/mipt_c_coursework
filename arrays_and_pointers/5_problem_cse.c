#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

typedef int (*cmp_t)(void const *lhs, void const *rhs);

int cmp(void const *lhs, void const *rhs) {
    const int a = *((int const *) lhs);
    const int b = *((int const *) rhs);

    if (a < b) return 1;

    return 0;
}

int selstep(void *parr, int eltsize, int numelts, int nsorted, cmp_t cmp) {
    const char *lhs = parr;
    lhs += nsorted ? nsorted - 1 * eltsize : 0;
    const int lhs_elem = *((int const *) lhs);

    char *rhs = parr;
    rhs += nsorted * eltsize;
    int elem = *((int const *) rhs);

    int delta = nsorted > 0 ? elem - lhs_elem : elem;
    int new_pos = nsorted;

    for (int i = nsorted; i < numelts; ++i) {
        rhs = parr + i * eltsize;
        elem = *((int const *) rhs);
        if (nsorted > 0 && cmp(lhs, rhs) == 0 && elem - lhs_elem < delta) {
            delta = elem - lhs_elem;
            new_pos = i;
        } else if (nsorted == 0 && elem < delta) {
            delta = elem;
            new_pos = i;
        }
    }

    if (new_pos != nsorted) {
        int temp = parr[nsorted];
        parr[nsorted] = parr[new_pos];
        parr[new_pos] = temp;
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

    selstep(arr, 1, sz, pos, cmp);

    free(arr);

    return 0;
}
