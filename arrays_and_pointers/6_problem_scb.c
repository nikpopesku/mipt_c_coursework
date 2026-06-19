#include <assert.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef int (*cmp_t)(const void *lhs, const void *rhs);

int cmp(void const *lhs, void const *rhs) {
}

void *cbsearch(const void *key, const void *base, int num, int size, cmp_t cmp) {

}

int main() {
    int sz;
    const int res = scanf("%d", &sz);
    assert(res == 1);

    int* arr = calloc(sz, sizeof(int));
    for (int i = 0; i < sz; ++i) {
        const int res2 = scanf("%d", &arr[i]);
        assert(res2 == 1);
    }

    free(arr);
    return 0;
}
