#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

struct node_t {
    struct node_t *next;
    int data;
};


// struct node_t * reverse(struct node_t *top) {
//     struct node_t *xs;
//     if (NULL == top) return NULL;
//     if (NULL == top->next) return top;
//     xs = reverse(top->next);
//     top->next->next = top;
//     top->next = NULL;
//     return xs;
// }


struct node_t *reverse(struct node_t *top) {
    struct node_t *prev;
    struct node_t *cur;
    if (top == NULL) return NULL;
    if (top->next == NULL) return top;
    prev = top;
    cur = top->next;
    prev->next = NULL;

    while (cur != NULL) {
        struct node_t *nxt = cur->next;
        cur->next = prev;
        prev = cur;
        cur = nxt;
    }

    return prev;
}

struct node_t *make_node(int data, struct node_t *next) {
    struct node_t *n = malloc(sizeof(struct node_t));
    n->data = data;
    n->next = next;
    return n;
}

int main() {
    // Пример 1: 2 -> 4 -> 6 -> 1, ожидаемый результат: 1 -> 6 -> 4 -> 2
    struct node_t *list = make_node(2, make_node(4, make_node(6, make_node(1, NULL))));

    struct node_t *result = reverse(list);

    int expected[] = {1, 6, 4, 2};
    int i = 0;
    for (struct node_t *cur = result; cur != NULL; cur = cur->next, i++) {
        printf("%d ", cur->data);
        assert(cur->data == expected[i]);
    }
    printf("\n");
    assert(i == 4);
    printf("OK\n");

    return 0;
}
