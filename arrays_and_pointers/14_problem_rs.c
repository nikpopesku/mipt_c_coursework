#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

int main() {
    unsigned sz;
    int * arr;
    int i;
    int res = scanf("%u", &sz);
    assert(res == 1);

    arr = calloc(sz, sizeof(int));

    for (i = 0; i < sz; ++i) {
        res = scanf("%d", &arr[i]);
        assert(res == 1);
    }

    return 0;
}
