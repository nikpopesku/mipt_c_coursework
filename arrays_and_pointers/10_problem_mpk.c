#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

void karatsuba(int *arr1, int* arr2, int* res, unsigned sz) {

}

int main() {
    unsigned sz1;
    unsigned sz2;
    int i;
    int j;
    int *arr1;
    int *arr2;
    int *result;
    int res = scanf("%u", &sz1);
    assert(res == 1);

    res = scanf("%u", &sz2);
    assert(res == 1);

    arr1 = calloc(sz1, sizeof(int));
    arr2 = calloc(sz2, sizeof(int));
    result = calloc(2 * sz2, sizeof(int));

    for (i = 0; i < sz1; ++i) {
        res = scanf("%d", &arr1[i]);
        assert(res == 1);
    }

    for (i = 0; i < sz2; ++i) {
        res = scanf("%d", &arr2[i]);
        assert(res == 1);
    }

    karatsuba(arr1, arr2, result, sz1);

    i = 2 * sz1 - 1;

    while (result[i] == 0) --i;
    for (j = 0; j <= i; ++j) {
        printf("%d ", result[j]);
    }

    printf("\n");

    return 0;
}
