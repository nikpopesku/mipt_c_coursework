#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

int main() {
    unsigned sz;
    unsigned q;
    unsigned i;
    unsigned * distance;
    int res = scanf("%u", &sz);
    assert(res == 1);
    distance = calloc(sz, sizeof(unsigned));

    for (i = 0; i < sz; ++i) {
        res = scanf("%u", &distance[i]);
    }

    res = scanf("%u", &q);
    assert(res == 1);

    free(distance);

    return 0;
}
