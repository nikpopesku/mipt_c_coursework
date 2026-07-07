#include <assert.h>
#include <stdio.h>
#include <stddef.h>

struct tree_t {
    struct tree_t *left;
    struct tree_t *right;
    int data;
};

void print_pre(struct tree_t *top) {
    if (top == NULL) return;

    printf("%d ", top->data);

    if (top->left) {
        print_pre(top->left);
    }

    if (top->right) {
        print_pre(top->right);
    }
}


int main() {
    return 0;
}
