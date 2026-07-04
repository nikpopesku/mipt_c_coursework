#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

struct node_t {
    struct node_t *next;
    int data;
};

int main() {
    unsigned sz;
    int res = scanf("%u", &sz);
    assert(res == 1);

    int * arr = calloc(sz, sizeof(int));

    for (int i = 0; i < sz; ++i) {
        res = scanf("%d", &arr[i]);
        assert(res == 1);
    }

    return 0;
}
