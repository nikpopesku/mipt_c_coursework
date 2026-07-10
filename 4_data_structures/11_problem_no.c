#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

struct tree_t {
    struct tree_t *left;
    struct tree_t *right;
    int data;
};

int main() {
    FILE *fptr = fopen("input.txt", "r");
    unsigned sz;
    int res;
    int *arr;
    int i;

    if (fptr == NULL) {
        // 3. Check for errors
        printf("Error opening file!\n");
        return 1;
    }

    res = fscanf(fptr, "%u", &sz);
    assert(res == 1);

    arr = malloc(sz * sizeof(int));
    for (i = 0; i < sz; ++i) {
        res = fscanf(fptr, "%d", &arr[i]);
        assert(res == 1);
    }


    fclose(fptr);

    return 0;
}
