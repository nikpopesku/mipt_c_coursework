#include <assert.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

int N = 2;

void powNxN (unsigned (*A)[N], unsigned k, unsigned m) {

}

int main() {
    int k, m;
    unsigned * arr;
    int i, j;
    int res = scanf("%d", &k);
    assert(res == 1);
    res = scanf("%d", &m);
    assert(res == 1);

    calloc(N * N, sizeof(unsigned));

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
