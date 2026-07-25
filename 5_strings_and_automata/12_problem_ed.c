#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

unsigned min(const unsigned a, const unsigned b, const unsigned c) {
    unsigned temp = a > b ? b : a;
    temp = temp > c ? c : temp;

    return temp;
}

int main() {
    unsigned add, delete, edit;
    unsigned sz1, sz2, i, row, col;
    unsigned **dp;
    char *st1, *st2;

    int res = scanf("%u", &add);
    assert(res == 1);

    res = scanf("%u", &delete);
    assert(res == 1);

    res = scanf("%u", &edit);
    assert(res == 1);

    res = scanf("%u", &sz1);
    assert(res == 1);

    getchar();

    st1 = calloc(sz1 + 1, sizeof(char));
    for (i = 0; i < sz1; ++i) {
        res = scanf("%c", &st1[i]);
        assert(res == 1);
    }

    st1[i] = '\0';

    getchar();

    res = scanf("%u", &sz2);
    assert(res == 1);

    st2 = calloc(sz2 + 1, sizeof(char));
    for (i = 0; i < sz2; ++i) {
        res = scanf("%c", &st2[i]);
        assert(res == 1);
    }

    st2[i] = '\0';

    dp = calloc(sz1 + 1, sizeof(unsigned *));

    for (row = 0; row <= sz1; ++row) {
        dp[row] = calloc(sz2 + 1, sizeof(unsigned));
        if (row > 0) {
            dp[row][0] = dp[row - 1][0] + 1;
        }
    }

    for (col = 1; col <= sz2; ++col) {
        dp[0][col] = dp[0][col - 1] + 1;
    }

    for (row = 1; row <= sz1; ++row) {
        for (col = 1; col <= sz2; ++col) {
            dp[row][col] = min(dp[row - 1][col - 1] + (st1[row - 1] != st2[col - 1] ? edit : 0), dp[row][col - 1] + add,
                               dp[row - 1][col] + delete);
        }
    }

    printf("%u\n", dp[sz1][sz2]);

    for (row = 1; row <= sz1; ++row) {
        free(dp[row]);
    }

    free(st1);
    free(st2);


    return 0;
}
