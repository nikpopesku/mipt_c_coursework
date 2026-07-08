#include <assert.h>
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>

struct tree_t {
    struct tree_t *left;
    struct tree_t *right;
    int data;
};


int main() {
    unsigned sz;
    int * preorder;
    int * inorder;

    int res = scanf("%d", &sz);
    assert(res == 1);

    preorder = malloc(sz * sizeof(int));
    inorder = malloc(sz * sizeof(int));

    for (int i = 0; i < sz; ++i) {
        res = scanf("%d", &preorder[i]);
        assert(res == 1);
    }

    for (int i = 0; i < sz; ++i) {
        res = scanf("%d", &inorder[i]);
        assert(res == 1);
    }

    free(preorder);
    free(inorder);

    return 0;
}
