#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void karatsuba(int *arr1, int *arr2, int *res, unsigned n) {
    int i;
    int j;
    int k = n / 2;
    int l[k];
    int r[k];
    int t[n];
    memset(t, 0, n * sizeof(int));
    int *t1 = t, *t2 = t + k;
    int *s1 = res, *s2 = res + k, *s3 = res + 2 * k, *s4 = res + 3 * k;

    if (n <= 64) {
        for (i = 0; i < n; i++)
            for (j = 0; j < n; j++)
                res[i + j] += arr1[i] * arr2[j];
    } else {
        for (i = 0; i < k; i++) {
            l[i] = arr1[i] + arr1[k + i];
            r[i] = arr2[i] + arr2[k + i];
        }
        karatsuba(l, r, t, k); // считает t
        karatsuba(arr1, arr2, res, k); // считает p1
        karatsuba(arr1 + k, arr2 + k, res + n, k); // считает p2
        for (i = 0; i < k; i++) {
            const int c1 = s2[i] + t1[i] - s1[i] - s3[i];
            const int c2 = s3[i] + t2[i] - s2[i] - s4[i];
            res[k + i] = c1;
            res[n + i] = c2;
        }
    }
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

    free(arr1);
    free(arr2);
    free(result);

    return 0;
}
