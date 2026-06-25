#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

int majority_element(const int *parr, int len) {
    int i;
    int elem = -1;
    int elem_back = -1;
    int count = 0;
    int count_back = 0;
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

    for (i = len - 1; i >= 0; --i) {
        if (count_back == 0) {
            elem_back = parr[i];
            ++count_back;
        } else if (count_back > 0 && elem_back != parr[i]) {
            --count_back;
        } else {
            ++count_back;
        }
    }

    return elem == elem_back && count > 0 && count_back > 0 ? elem : -1;
}

int main() {
    unsigned sz;
    int i;
    int res = scanf("%u", &sz);
    int *parr;
    assert(res == 1);

    parr = calloc(sz, sizeof(int));

    for (i = 0; i < sz; ++i) {
        res = scanf("%d", &parr[i]);
        assert(res == 1);
    }

    printf("%d\n", majority_element(parr, sz));

    return 0;
}
