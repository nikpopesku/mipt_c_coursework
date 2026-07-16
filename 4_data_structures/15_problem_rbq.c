#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

int find_index_left(const unsigned sz, const unsigned *distance, const unsigned value) {
    unsigned left = 0;
    unsigned right = sz;
    while (left < right) {
        const unsigned m = left + (right - left) / 2;

        if (distance[m] > value) {
            right = m - 1;
        } else {
            left = m;
        }
    }

    return left;
}

int find_index_right(const unsigned sz, const unsigned *distance, const unsigned value) {
    unsigned left = 0;
    unsigned right = sz;
    while (left < right) {
        const unsigned m = left + (right - left) / 2;

        if (distance[m] > value) {
            right = m - 1;
        } else {
            left = m;
        }
    }

    return left;
}

int main() {
    unsigned sz, q, i, left, right, index1, index2;
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

        index1 = find_index_left(sz, distance, left);

        res = scanf("%u", &right);
        assert(res == 1);

        index2 = find_index_right(sz, distance, left);

        printf("%u", index2 - index1 + 1);
    }

    free(distance);

    return 0;
}
