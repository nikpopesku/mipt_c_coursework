#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

int majority_element(const int *parr, int len) {
    int i;
    int elem = -1;
    int count = 0;
    for (i = 0; i < len; ++i) {
        if (count == 0) {
            elem = parr[i];
            ++count;
        } else if (count > 0 && elem != parr[i]) {
            --count;
        } else {
            ++count;
        }
    }

    return elem;
}

int main() {
    unsigned sz;
    int i;
    int res = scanf("%u", &sz);
    int *parr;
    assert(res == 1);

    parr = calloc(sz, sizeof(int));

    for (i = 0; i < sz; ++i) {
        res = scanf("%u", &parr[i]);
        assert(res == 1);
    }

    printf("%d\n", majority_element(parr, sz));

    return 0;
}
