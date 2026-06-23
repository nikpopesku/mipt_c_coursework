#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
void merge(int *arr, int l, int m, int r);

void merge_sort_imp(int *arr, int l, int r) {
    if (l >= r) return;
    int m = (l + r) / 2;
    merge_sort_imp(arr, l, m);
    merge_sort_imp(arr, m + 1, r);
    merge(arr, l, m, r);
}

void merge_sort(int *arr, int n) {
    merge_sort_imp(arr, 0, n - 1);
}

int main() {
    unsigned sz;
    int i;
    int res = scanf("%u", &sz);
    int * arr;

    assert(res == 1);
    arr = calloc(sz, sizeof(int));

    for (i = 0; i < sz; ++i) {
        res = scanf("%d", &arr[i]);
        assert(res == 1);
    }

    return 0;
}
