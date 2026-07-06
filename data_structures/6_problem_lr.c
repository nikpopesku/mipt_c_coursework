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


struct node_t * reverse(struct node_t *top) {

}

int main() {
    return 0;
}
