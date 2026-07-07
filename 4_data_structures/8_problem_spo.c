#include <stdio.h>
#include <stdlib.h>

struct tree_t {
    struct tree_t *left;
    struct tree_t *right;
    int data;
};

struct stacktree_t {
    struct stacktree_t *next;
    struct tree_t *data;
};

void push(struct stacktree_t **s, struct tree_t *t) {
    struct stacktree_t *tmp = calloc(1, sizeof(struct stacktree_t));
    tmp->data = t;
    tmp->next = *s;
    *s = tmp;
}

void print_pre(struct tree_t *top) {
    struct stacktree_t *s = NULL;
    struct stacktree_t *tmp;
    push(&s, top);

    while (s) {
        printf("%d ", s->data->data);
        tmp = s;
        s = s->next;

        if (tmp->data->right) {
            push(&s, tmp->data->right);
        }

        if (tmp->data->left) {
            push(&s, tmp->data->left);
        }

        free(tmp);
    }
}

int main() {
    return 0;
}
