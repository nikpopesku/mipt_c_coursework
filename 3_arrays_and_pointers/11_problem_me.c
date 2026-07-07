#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

int majority_element(const int *parr, int len) {
    int i;
    int elem = -1;
    int count = 0;

    /* Boyer-Moore: find a candidate */
    for (i = 0; i < len; ++i) {
        if (count == 0) {
            elem = parr[i];
            ++count;
        } else if (elem != parr[i]) {
            --count;
        } else {
            ++count;
        }
    }

    /* Verify the candidate actually occurs more than len/2 times */
    count = 0;
    for (i = 0; i < len; ++i) {
        if (parr[i] == elem) {
            ++count;
        }
    }

    return count > len / 2 ? elem : -1;
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
