#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

int main() {
    unsigned backpack, sz;
    unsigned * weight;
    int res = scanf("%u", &backpack);
    assert(res == 1);

    res = scanf("%u", &sz);
    assert(res == 1);

    weight = calloc(sz, sizeof(unsigned));

    for (int i = 0; i < sz; ++i) {
        scanf("%u", &weight[i]);
    }

    return 0;
}
