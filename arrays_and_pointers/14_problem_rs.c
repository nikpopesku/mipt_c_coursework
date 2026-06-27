#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

int main() {
    unsigned sz;
    int *arr;
    int i;
    int radix;
    int base = 1;
    int res = scanf("%u", &sz);
    int *bucket = calloc(10, sizeof(int));
    assert(res == 1);

    arr = calloc(sz, sizeof(int));

    for (i = 0; i < sz; ++i) {
        res = scanf("%d", &arr[i]);
        assert(res == 1);
    }

    res = scanf("%d", &radix);
    assert(res == 1);

    for (i = 0; i < radix; ++i) base *= 10;
    for (i = 0; i < sz; ++i) ++bucket[(arr[i] / base) % 10];

    return 0;
}
