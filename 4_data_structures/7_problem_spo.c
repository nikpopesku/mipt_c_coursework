#include <assert.h>
#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>

struct tree_t {
    struct tree_t *left;
    struct tree_t *right;
    int data;
};

struct node_t {
    struct node_t *next;
    int data;
};

struct node_t *create_preorder(struct tree_t *tree) {
    struct node_t *top;
    struct node_t *node;
    if (tree == NULL) return NULL;

    top = calloc(1, sizeof(struct node_t));
    node = top;

    if (tree->left) {
        node->next = create_preorder(tree->left);
        node = node->next;
    }

    if (tree->right) {
        node->next = create_preorder(tree->right);
    }


    node = NULL;

    return top;
}

void print_pre(struct tree_t *top) {
    const struct node_t *node = create_preorder(top);

    while (node) {
        printf("%d ", node->data);
        node = node->next;
    }
}

int main() {
    return 0;
}
