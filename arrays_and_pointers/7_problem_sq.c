#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

unsigned partition(int *arr, unsigned low, unsigned high) {
    return 5;
}

void qsort_impl(int *arr, unsigned low, unsigned high) {
    if (low >= high) return;
    unsigned pi = partition(arr, low, high);
    if (pi > low) qsort_impl(arr, low, pi - 1);
    qsort_impl(arr, pi + 1, high);
}

void qsort(int *arr, unsigned len) {
    qsort_impl(arr, 0u, len - 1);
}

int main() {
    unsigned sz;
    int i;
    int res = scanf("%d", &sz);
    assert(res == 1);

    int *arr = calloc(sz, sizeof(int));

    for (i = 0; i < sz; ++i) {
        res = scanf("%d", &arr[i]);
        assert(res == 1);
    }

    qsort(arr, sz);

    free(arr);

    return 0;
}
