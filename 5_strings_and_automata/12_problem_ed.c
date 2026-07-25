#include <assert.h>
#include <stdio.h>
#include <stdlib.h>


int main() {
    unsigned add, delete, edit;
    unsigned sz1, sz2, i;
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

    st1 = calloc(sz1 + 1, sizeof(char));
    for (i = 0; i < sz1; ++i) {
        res = scanf("%c", &st1[i]);
        assert(res == 1);
    }

    st1[i] = '\0';

    res = scanf("%u", &sz2);
    assert(res == 1);

    st2 = calloc(sz2 + 1, sizeof(char));
    for (i = 0; i < sz2; ++i) {
        res = scanf("%c", &st2[i]);
        assert(res == 1);
    }

    st2[i] = '\0';

    dp = calloc(sz1 + 1, sizeof(unsigned *));

    for (i = 0; i <= sz1; ++i) {
        dp[i] = calloc(sz2, sizeof(unsigned));
    }


    return 0;
}
