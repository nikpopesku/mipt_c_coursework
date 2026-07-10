#include <stdlib.h>
#include "func.h"

typedef int (*get_hash_t)(const char *s);

int ncollisions(char **strs, int n, get_hash_t f) {
    int counter = 0;
    int i = 0;
    int val;
    int *arr = calloc(HASH_MAX, sizeof(int));

    for (i = 0; i < n; ++i) {
        val = f(strs[i]);

        if (arr[val] >= 1) {
            ++counter;
        }

        ++arr[val];
    }

    free(arr);

    return counter;
}


int main() {
    return 0;
}
