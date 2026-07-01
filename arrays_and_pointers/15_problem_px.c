#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

int N = 2;

void powNxN(unsigned (*A)[N], unsigned k, unsigned m) {
}

int main() {
    int k, m;
    unsigned (*arr)[N];
    int i, j;
    int res = scanf("%d", &k);
    assert(res == 1);
    res = scanf("%d", &m);
    assert(res == 1);

    arr = calloc(N, sizeof(unsigned [N]));

    for (i = 0; i < N; ++i) {
        for (j = 0; j < N; ++j) {
            res = scanf("%u", &arr[i][j]);
            assert(res == 1);
        }
    }

    powNxN(arr, k, m);

    free(arr);


    return 0;
}
