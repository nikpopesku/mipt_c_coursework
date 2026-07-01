#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

int N = 10;

void powNxN(unsigned (*A)[N], unsigned k, unsigned m) {
    int row, col, l;
    unsigned long long value;
    unsigned (*B)[N] = calloc(N, sizeof(unsigned [N]));
    unsigned (*C)[N] = calloc(N, sizeof(unsigned [N]));

    for (row = 0; row < N; ++row)
        for (col = 0; col < N; ++col) {
            B[row][col] = (row == col) ? 1 % m : 0;
            A[row][col] %= m;
        }

    while (k > 0) {
        if (k & 1) {
            for (row = 0; row < N; ++row) {
                for (col = 0; col < N; ++col) {
                    value = 0;
                    for (l = 0; l < N; ++l)
                        value = (value + (unsigned long long)B[row][l] * A[l][col]) % m;
                    C[row][col] = (unsigned)value;
                }
            }
            for (row = 0; row < N; ++row)
                for (col = 0; col < N; ++col)
                    B[row][col] = C[row][col];
        }
        for (row = 0; row < N; ++row) {
            for (col = 0; col < N; ++col) {
                value = 0;
                for (l = 0; l < N; ++l)
                    value = (value + (unsigned long long)A[row][l] * A[l][col]) % m;
                C[row][col] = (unsigned)value;
            }
        }
        for (row = 0; row < N; ++row)
            for (col = 0; col < N; ++col)
                A[row][col] = C[row][col];

        k >>= 1;
    }

    for (row = 0; row < N; ++row)
        for (col = 0; col < N; ++col)
            A[row][col] = B[row][col];

    free(B);
    free(C);
}

int main() {
    unsigned k, m;
    unsigned (*arr)[N];
    int i, j;
    int res = scanf("%u", &m);
    assert(res == 1);
    res = scanf("%u", &k);
    assert(res == 1);

    arr = calloc(N, sizeof(unsigned [N]));

    for (i = 0; i < N; ++i) {
        for (j = 0; j < N; ++j) {
            res = scanf("%u", &arr[i][j]);
            assert(res == 1);
        }
    }

    powNxN(arr, k, m);

    for (i = 0; i < N; ++i) {
        for (j = 0; j < N; ++j) {
            printf("%u ", arr[i][j]);
        }
        printf("\n");
    }

    free(arr);


    return 0;
}
