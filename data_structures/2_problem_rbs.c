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

    struct node_t **bucket = calloc(sz, sizeof(struct node_t *));
    const int bucket_size = mx / sz;

    for (int i = 0; i < sz; ++i) {
        const int num = arr[i] / bucket_size;
        struct node_t *node = bucket[num];
        if (node == NULL) {
            bucket[num] = malloc(sizeof(struct node_t));
            bucket[num]->data = arr[i];
        } else {
            while (node != NULL && node->data < arr[i] && node->next != NULL) {
                node = node->next;
            }
            struct node_t *new_node = malloc(sizeof(struct node_t));
            new_node->data = arr[i];

            if (node->data < arr[i]) {
                if (node->next) {
                    struct node_t *tmp = node->next;
                    node->next = new_node;
                    new_node->next = tmp;
                } else {
                    node->next = new_node;
                }
            } else {
                new_node->next = node;
                bucket[num] = new_node;
            }
        }
    }

    for (int i = 0; i < sz; ++i) {
        printf("0 ");

        struct node_t *node = bucket[i];
        while (node != NULL) {
            printf("%d ", node->data);
            node = node->next;
        }
    }

    printf("0\n");


    return 0;
}
