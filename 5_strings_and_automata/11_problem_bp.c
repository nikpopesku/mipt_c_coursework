#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

unsigned max(const unsigned a, const unsigned b) {
    return a > b ? a : b;
}

struct val {
    unsigned weight;
    unsigned count;
};

int main() {
    unsigned backpack, sz;
    unsigned *weight, row, col;
    struct val **dp;
    int res = scanf("%u", &backpack);
    assert(res == 1);

    res = scanf("%u", &sz);
    assert(res == 1);

    weight = calloc(sz + 1, sizeof(unsigned));

    for (int i = 1; i <= sz; ++i) {
        scanf("%u", &weight[i]);
    }

    dp = calloc(sz + 1, sizeof(struct val *));

    for (row = 0; row <= sz; ++row) {
        dp[row] = calloc(backpack + 1, sizeof(struct val));
    }

    for (row = 1; row <= sz; ++row) {
        for (col = 1; col <= backpack; ++col) {
            dp[row][col].weight = max(dp[row - 1][col].weight, col >= weight[row] ? dp[row - 1][col - weight[row]].weight + weight[row] : 0);
        }
    }

    printf("%u\n", dp[sz][backpack].count);

    for (row = 1; row <= sz; ++row) {
        free(dp[row]);
    }

    free(weight);

    return 0;
}
