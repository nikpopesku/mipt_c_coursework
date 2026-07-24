#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

int max(const int a, const int b) {
    return a > b ? a : b;
}

int main() {
    unsigned backpack, sz;
    unsigned *weight, row, col;
    unsigned **dp;
    int res = scanf("%u", &backpack);
    assert(res == 1);

    res = scanf("%u", &sz);
    assert(res == 1);

    weight = calloc(sz + 1, sizeof(unsigned));

    for (int i = 1; i <= sz; ++i) {
        scanf("%u", &weight[i]);
    }

    dp = calloc(sz + 1, sizeof(unsigned *));

    for (row = 0; row <= sz; ++row) {
        dp[row] = calloc(backpack + 1, sizeof(unsigned));
    }

    for (row = 1; row <= sz; ++row) {
        for (col = 1; col <= backpack; ++col) {
            dp[row][col] = max(dp[row - 1][col], dp[row - 1][col - weight[col]] + weight[col]);
        }
    }

    printf("%u\n", dp[sz][backpack]);

    return 0;
}
