#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

int N = 2;

void powNxN(unsigned long long (*A)[N], unsigned long long k, unsigned long long m) {
    int i, j, l;
    unsigned long long value;
    unsigned long long (*B)[N] = calloc(N, sizeof(unsigned long long [N]));

    for (i = 0; i < N; ++i) {
        for (j = 0; j < N; ++j) {
            B[i][j] = A[i][j];
        }
    }

    while (k-- > 1) {
        for (i = 0; i < N; ++i) {
            for (j = 0; j < N; ++j) {
                value = 0;
                for (l = 0; l < N; ++l) {
                    value = (value + B[i][l] % m * (A[l][j] % m) % m) % m;
                }
                B[i][j] = value;
            }
        }
    }

    for (i = 0; i < N; ++i) {
        for (j = 0; j < N; ++j) {
            A[i][j] = B[i][j];
        }
    }

    free(B);
}

int main() {
    unsigned long long k, m;
    unsigned long long (*arr)[N];
    int i, j;
    int res = scanf("%llu", &k);
    assert(res == 1);
    res = scanf("%llu", &m);
    assert(res == 1);

    arr = calloc(N, sizeof(unsigned long long [N]));

    for (i = 0; i < N; ++i) {
        for (j = 0; j < N; ++j) {
            res = scanf("%llu", &arr[i][j]);
            assert(res == 1);
        }
    }

    powNxN(arr, k, m);

    for (i = 0; i < N; ++i) {
        for (j = 0; j < N; ++j) {
            printf("%llu ", arr[i][j]);
        }
        printf("\n");
    }

    free(arr);


    return 0;
}
