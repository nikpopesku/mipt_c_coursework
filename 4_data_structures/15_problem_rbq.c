#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

int find_index_left(const unsigned sz, const unsigned *distance, const unsigned value) {
    unsigned left = 0;
    unsigned right = sz - 1;

    while (left < right) {
        const unsigned m = left + (right - left + 1) / 2;

        if (distance[m] > value) {
            right = m > 0 ? m - 1 : 0;
        } else {
            left = m;
        }
    }

    return left;
}

int find_index_right(const unsigned sz, const unsigned *distance, const unsigned value) {
    unsigned left = 0;
    unsigned right = sz - 1;
    while (left < right) {
        const unsigned m = left + (right - left + 1) / 2;

        if (distance[m] > value) {
            right = m > 0 ? m - 1 : 0;
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

        index2 = find_index_right(sz, distance, right);

        printf("%u ", index2 - index1 + (distance[index1] >= left && distance[index2] <= right ? 1 : 0));
    }

    free(distance);

    return 0;
}
