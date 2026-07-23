#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <regex.h>

int main() {
    unsigned amount, sz, c, i;
    int res = scanf("%u", &amount);
    unsigned *coin, *dp;
    assert(res == 1);

    res = scanf("%u", &sz);
    assert(res == 1);

    coin = calloc(sz, sizeof(unsigned));
    dp = calloc(amount + 1, sizeof(unsigned));

    for (i = 0; i < sz; ++i) {
        res = scanf("%u", &coin[i]);
        dp[coin[i]] = 1;
        assert(res == 1);
    }

    for (i = 1; i <= amount; ++i) {
        for (c = 0; c < sz; ++c) {
            if (i >= coin[c]) {
                dp[i] = dp[i - coin[c]] + 1 > dp[i] ? dp[i] : dp[i - coin[c]] + 1;
            }
        }
    }

    printf("%u", dp[amount]);


    free(coin);


    return 0;
}
