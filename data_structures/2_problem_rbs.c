#include <assert.h>
#include <limits.h>
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
    int mx = INT_MIN;

    for (int i = 0; i < sz; ++i) {
        res = scanf("%d", &arr[i]);
        assert(res == 1);
        mx = mx > arr[i] ? mx : arr[i];
    }



    return 0;
}
