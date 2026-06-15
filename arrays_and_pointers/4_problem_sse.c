#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

int main() {
    int sz;

    const int res = scanf("%d", &sz);
    assert(res == 1);

    int *arr = calloc(sz, sizeof(int));

    free(arr);
    return 0;
}
