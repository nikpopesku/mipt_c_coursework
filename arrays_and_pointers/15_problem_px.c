#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

int N = 2;

void powNxN(unsigned long long (*A)[N], unsigned long long k, unsigned long long m) {
    int row, col, l;
    unsigned long long value;
    unsigned long long (*B)[N] = calloc(N, sizeof(unsigned long long [N]));
    unsigned long long (*C)[N] = calloc(N, sizeof(unsigned long long [N]));

    for (row = 0; row < N; ++row) {
        for (col = 0; col < N; ++col) {
            B[row][col] = A[row][col];
        }
    }

    while (k-- > 1) {
        for (row = 0; row < N; ++row) {
            for (col = 0; col < N; ++col) {
                value = 0;
                for (l = 0; l < N; ++l) {
                    value = (value + B[row][l] % m * (A[l][col] % m) % m) % m;
                }
                C[row][col] = value;
            }
        }
        for (row = 0; row < N; ++row) {
            for (col = 0; col < N; ++col) {
                B[row][col] = C[row][col];
            }
        }
    }

    for (row = 0; row < N; ++row) {
        for (col = 0; col < N; ++col) {
            A[row][col] = B[row][col];
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
