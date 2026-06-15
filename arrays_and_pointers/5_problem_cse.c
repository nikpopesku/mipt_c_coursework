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
    char *elem_ptr = parr;
    char *previous_elem_ptr = parr;
    elem_ptr += nsorted * eltsize;
    previous_elem_ptr += nsorted ? nsorted - 1 * eltsize : 0;
    int previous_elem = *((int const *) previous_elem_ptr);

    int delta = nsorted > 0 ? elem - previous_elem : elem;
    int new_pos = nsorted;

    for (int i = nsorted; i < numelts; ++i) {
        char *lhs = parr;
        char *rhs = parr;
        if (nsorted > 0) {
            lhs += (nsorted - 1) * eltsize;
        }
        rhs += i * eltsize;
        const int elem = *((int const *) rhs);
        if (nsorted > 0 && cmp(lhs, rhs) == 0 && elem - previous_elem < delta) {
            delta = elem - previous_elem;
        } else if (nsorted == 0 && previous_elem < delta) {
            delta = previous_elem;
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
