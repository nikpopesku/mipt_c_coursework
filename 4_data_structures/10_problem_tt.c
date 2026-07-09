#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

void print_postorder(int *preorder, int *inorder, const int begin_preorder, const int begin_inorder,
                     const int end_inorder) {
    int count;
    printf("%d ", preorder[begin_preorder]);

    if (begin_inorder + 1 == end_inorder) return;

    for (count = begin_inorder; count < end_inorder; ++count) {
        if (inorder[count] == preorder[begin_preorder]) break;
    }

    print_postorder(preorder, inorder, begin_preorder + 1, begin_inorder, count);
}


int main() {
    int sz;
    int *preorder;
    int *inorder;

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

    print_postorder(preorder, inorder, 0, 0, sz);

    free(preorder);
    free(inorder);

    return 0;
}
