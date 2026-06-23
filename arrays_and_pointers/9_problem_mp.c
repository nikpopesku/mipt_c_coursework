#include <assert.h>
#include <stdio.h>
#include <stdlib.h>


int * calc(int * arr1, int * arr2, unsigned sz1, unsigned sz2) {

}


int main() {
    int sz1;
    int sz2;
    int i;
    int *arr1;
    int *arr2;
    int * arr;
    int res = scanf("%d", &sz1);
    assert(res == 1);
    res = scanf("%d", &sz2);
    assert(res == 2);
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

    free(arr1);
    free(arr2);

    arr = calc(arr1, arr2, sz1, sz2);

    for (i = sz1 + sz2 - 1; i >= 0; --i) {
        printf("%d ", arr[i]);
    }

    printf("\n");

    free(arr);

    return 0;
}
