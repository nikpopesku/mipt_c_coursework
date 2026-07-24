#include <assert.h>
#include <stdio.h>
#include <stdlib.h>


struct val {
    unsigned weight;
    unsigned count;
};

struct val max(const struct val a, const struct val b) {
    return a.weight > b.weight ? a : b;
}


int main() {
    unsigned backpack, sz;
    unsigned *weight, row, col;
    struct val **dp, xxx;
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
        struct val temp;
        temp.weight = 0;
        temp.count = 0;

        for (col = 1; col <= backpack; ++col) {
            if (col > weight[row]) {
                xxx = temp;
            } else {
                xxx = dp[row - 1][col - weight[row]];
                xxx.weight += weight[row];
                xxx.count += 1;
            }
            dp[row][col] = max(dp[row - 1][col], xxx);
        }
    }

    printf("%u\n", dp[sz][backpack].count);

    for (row = 1; row <= sz; ++row) {
        free(dp[row]);
    }

    free(weight);

    return 0;
}
