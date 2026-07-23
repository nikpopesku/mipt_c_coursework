#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <regex.h>

int main() {
    unsigned amount, sz, c, i, j;
    int res = scanf("%u", &amount);
    int *coin, *dp;
    assert(res == 1);

    res = scanf("%u", &sz);
    assert(res == 1);

    coin = calloc(sz, sizeof(unsigned));
    dp = calloc(amount + 1, sizeof(unsigned));
    for (i = 1; i <= amount; ++i) dp[i] = -1;

    for (i = 0; i < sz; ++i) {
        res = scanf("%d", &coin[i]);
        assert(res == 1);
    }

    for (i = 1; i <= amount; ++i) {
        for (c = 0; c < sz; ++c) {
            if (i >= coin[c]) {
                if (dp[i] == -1) {
                    dp[i] = 1;
                } else {
                    dp[i] = dp[i - coin[c]] + 1 > dp[i] ? dp[i] : dp[i - coin[c]] + 1;
                }
            }
        }
        for (j = 0; j <= amount; ++j) {
            printf("%d ", dp[i]);
        }
        printf("\n");
    }

    printf("%d", dp[amount] != -1 ? dp[amount] : 0);


    free(coin);
    free(dp);


    return 0;
}
