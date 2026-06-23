#include <assert.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>


int *calc(const int *arr1, const int *arr2, const unsigned sz1, const unsigned sz2) {
    int *arr = calloc(sz1 + sz2 - 1, sizeof(int));
    unsigned it1;
    unsigned it2;

    for (it1 = 0; it1 < sz1; ++it1) {
        for (it2 = 0; it2 < sz2; ++it2) {
            arr[it1 + it2] += arr1[it1] * arr2[it2];
        }
    }

    return arr;
}


int main() {
    unsigned sz1;
    unsigned sz2;
    unsigned i;
    unsigned j;
    int *arr1;
    int *arr2;
    int *arr;
    int res = scanf("%u", &sz1);
    assert(res == 1);
    res = scanf("%u", &sz2);
    assert(res == 1);
    arr1 = calloc(sz1, sizeof(int));
    arr2 = calloc(sz2, sizeof(int));

    for (i = 0; i < sz1; ++i) {
        res = scanf("%d", &arr1[i]);
        assert(res == 1);
    }

    for (i = 0; i < sz2; ++i) {
        res = scanf("%d", &arr2[i]);
        assert(res == 1);
    }


    arr = calc(arr1, arr2, sz1, sz2);

    i = sz1 + sz2 - 1;
    while (arr[i] == 0) --i;

    for (j = 0; j <= i; ++j) {
        printf("%d ", arr[j]);
    }

    printf("\n");

    free(arr);
    free(arr1);
    free(arr2);

    return 0;
}
