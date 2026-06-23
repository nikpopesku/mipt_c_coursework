#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

void merge(int *arr, int l, int m, int r) {
    int *p1;
    int *p2;
    int *temp = calloc(r - l + 1, sizeof(int));
    int *it = temp;
    p1 = arr + l;
    p2 = arr + m + 1;

    while (p1 <= arr + m && p2 <= arr + r) *it++ = *p1 > *p2 ? *p2++ : *p1++;
    while (p1 <= arr + m) *it++ = *p1++;
    while (p2 <= arr + r) *it++ = *p2++;

    p1 = arr + l;
    it = temp;
    while (p1 <= arr + r) *p1++ = *it++;
}

void merge_sort_imp(int *arr, int l, int r) {
    int m;
    if (l >= r) return;
    m = (l + r) / 2;
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
    int *arr;

    assert(res == 1);
    arr = calloc(sz, sizeof(int));

    for (i = 0; i < sz; ++i) {
        res = scanf("%d", &arr[i]);
        assert(res == 1);
    }

    merge_sort(arr, sz);

    for (i = 0; i < sz; ++i) {
        printf("%d ", arr[i]);
    }

    printf("\n");

    free(arr);

    return 0;
}
