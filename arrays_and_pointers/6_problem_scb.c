#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

typedef int (*cmp_t)(const void *lhs, const void *rhs);

int intcmp(void const *lhs, void const *rhs) {
    const int *a = lhs;
    const int *b = rhs;

    if (*a < *b) return -1;
    if (*a > *b) return 1;

    return 0;
}

void *cbsearch(const void *key, const void *base, int num, int size, cmp_t intcmp) {
    int *lhs = base;
    int *rhs = base + (num - 1) * size;

    while (lhs < rhs) {
        int *m = lhs + (rhs - lhs) / 2;
        const int val = intcmp(m, key);

        if (val == 0) {
            return m;
        }

        if (val > 0) rhs = m;
        if (val < 0) lhs = m + 1;
    }

    int * keyp = key;

    return *lhs == *keyp ? lhs : base + num * size;
}

int main() {
    int sz;
    const int res = scanf("%d", &sz);
    assert(res == 1);

    int *arr = calloc(sz, sizeof(int));
    for (int i = 0; i < sz; ++i) {
        const int res2 = scanf("%d", &arr[i]);
        assert(res2 == 1);
    }

    const void *key = arr + 3;

    void *found = cbsearch(key, arr, sz, sizeof(int), intcmp);
    int *val = found;

    printf("%d", *val);

    free(arr);
    return 0;
}
