#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

int main() {
    unsigned sz;
    int *arr;
    int i;
    int j;
    int radix;
    int base = 1;
    int res = scanf("%u", &sz);
    assert(res == 1);

    arr = calloc(sz, sizeof(int));

    for (i = 0; i < sz; ++i) {
        res = scanf("%d", &arr[i]);
        assert(res == 1);
    }

    res = scanf("%d", &radix);
    assert(res == 1);

    for (i = 0; i < radix; ++i) base *= 10;

    for (i = 0; i < 10; ++i) {
        for (j = 0; j < sz; ++j) {
            if (arr[j] / base % 10 == i) printf("%d ", arr[j]);
        }
    }

    return 0;
}
