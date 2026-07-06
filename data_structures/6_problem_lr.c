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
    if (top == NULL) return NULL;
    if (top->next == NULL) return top;
    struct node_t *prev = top;
    struct node_t *cur = top->next;
    prev->next = NULL;

    while (cur != NULL) {
        struct node_t *nxt = cur->next;
        cur->next = prev;
        prev = cur;
        cur = nxt;
    }

    return prev;
}

int main() {
    return 0;
}
