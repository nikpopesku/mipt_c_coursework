#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <regex.h>

int main() {
    unsigned amount, sz, i;
    int res = scanf("%u", &amount);
    unsigned *coin;
    assert(res == 1);

    res = scanf("%u", &sz);
    assert(res == 1);

    coin = calloc(sz, sizeof(unsigned));

    for (i = 0; i < sz; ++i) {
        res = scanf("%u", &coin[i]);
        assert(res == 1);
    }


    free(coin);


    return 0;
}
