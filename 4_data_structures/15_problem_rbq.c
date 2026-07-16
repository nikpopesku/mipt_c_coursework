#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

int main() {
    unsigned sz, q, i, left, right;
    unsigned *distance;
    int res = scanf("%u", &sz);
    assert(res == 1);
    distance = calloc(sz, sizeof(unsigned));

    for (i = 0; i < sz; ++i) {
        res = scanf("%u", &distance[i]);
        assert(res == 1);
    }

    res = scanf("%u", &q);
    assert(res == 1);
    for (i = 0; i < q; ++i) {
        res = scanf("%u", &left);
        assert(res == 1);
        res = scanf("%u", &right);
        assert(res == 1);
    }

    free(distance);

    return 0;
}
