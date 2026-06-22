#include <assert.h>
#include <stdio.h>
#include <stdlib.h>


void printit(int *arr, unsigned sz) {
    int i;

    for (i = 0; i < sz; ++i) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

unsigned partition(int *arr, unsigned low, unsigned high) {
    if (low == high) return low;

    int *lhs = arr + low + 1;
    int *rhs = arr + high;

    while (lhs < rhs) {
        while (*lhs <= arr[low]) lhs += 1;
        while (*rhs > arr[low]) rhs -= 1;

        if (lhs < rhs) {
            const int temp = *lhs;
            *lhs = *rhs;
            *rhs = temp;
            rhs -= 1;
            lhs += 1;
        }
    }

    const int temp = arr[low];
    arr[low] = *(lhs - 1);
    *(lhs - 1) = temp;

    return lhs - 1 - arr;
}

void qsort_impl(int *arr, unsigned low, unsigned high) {
    if (low >= high) return;
    unsigned pi = partition(arr, low, high);
    if (pi > low) qsort_impl(arr, low, pi - 1);
    qsort_impl(arr, pi + 1, high);
}

void my_qsort(int *arr, unsigned len) {
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

    my_qsort(arr, sz);

    printit(arr, sz);

    free(arr);

    return 0;
}
