#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

int main() {
    unsigned sz;
    int i;
    int * arr;
    int * bucket;
    int res = scanf("%u", &sz);
    int mx = 0;
    assert(res == 1);
    arr = calloc(sz, sizeof(int));

    for (i = 0; i < sz; ++i) {
        res = scanf("%d", &arr[i]);
        assert(res == 1);
        if (i == 0) {
            mx = arr[i];
        } else {
            mx = arr[i] > mx ? arr[i] : mx;
        }
    }

    bucket = calloc(mx + 1, sizeof(int));
    for (i = 0; i < sz; ++i) ++bucket[arr[i]];

    for (i = 0; i <= mx; ++i) {
        printf("%d ", bucket[i]);
    }

    printf("\n");

    free(arr);
    free(bucket);

    return 0;
}
