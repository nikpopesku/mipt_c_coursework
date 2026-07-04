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

    int *arr = calloc(sz, sizeof(int));
    int mx = INT_MIN;

    for (int i = 0; i < sz; ++i) {
        res = scanf("%d", &arr[i]);
        assert(res == 1);
        mx = mx > arr[i] ? mx : arr[i];
    }

    struct node_t *bucket = malloc(sz * sizeof(struct node_t));
    const int bucket_size = mx / sz;

    for (int i = 0; i < sz; ++i) {
        const int num = arr[i] / bucket_size;
        struct node_t *node = &bucket[num];
        if (node == NULL) {
            bucket[num] = calloc(1, sizeof(struct node_t));
            bucket[num].data = arr[i];
        } else {
            while (node != NULL && node->data < arr[i] && node->next != NULL) {
                node = node->next;
            }
        }
    }


    return 0;
}
