#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

struct tree_t {
    struct tree_t *left;
    struct tree_t *right;
    int data;
};

void insert(struct tree_t *node, const int value) {
    if (node->data > value) {
        if (node->left) {
            insert(node->left, value);
        } else {
            node->left = malloc(sizeof(struct tree_t));
            node->left->data = value;
        }
    } else {
        if (node->right) {
            insert(node->right, value);
        } else {
            node->right = malloc(sizeof(struct tree_t));
            node->right->data = value;
        }
    }
}

void preorder(struct tree_t *node) {
    if (node == NULL) return;

    printf("%d ", node->data);
    preorder(node->left);
    preorder(node->right);
}

int main() {
    FILE *fptr = fopen("input.txt", "r");
    unsigned sz;
    int res;
    int val;
    int i;
    struct tree_t *root = malloc(sizeof(struct tree_t));

    if (fptr == NULL) {
        // 3. Check for errors
        printf("Error opening file!\n");
        return 1;
    }

    res = fscanf(fptr, "%u", &sz);
    assert(res == 1);

    for (i = 0; i < sz; ++i) {
        res = fscanf(fptr, "%d", &val);
        assert(res == 1);
        if (i == 0) {
            root->data = val;
        } else {
            insert(root, val);
        }
    }

    preorder(root);

    fclose(fptr);

    return 0;
}
