#include <limits.h>
#include <stdio.h>
#include <stdlib.h>

struct tree_t {
    struct tree_t *left;
    struct tree_t *right;
    int data;
};

int check_is_bst_internal(const struct tree_t *node, const int left, const int right) {
    int val;
    if (node == NULL) return 1;

    if (node->data <= left || node->data >= right) return 0;

    val = check_is_bst_internal(node->left, left, node->data);
    if (val == 0) return 0;

    val = check_is_bst_internal(node->right, node->data, right);
    if (val == 0) return 0;

    return 1;
}

int check_is_bst(struct tree_t *top) {
    return check_is_bst_internal(top, INT_MIN, INT_MAX);
}

int main() {
    return 0;
}
