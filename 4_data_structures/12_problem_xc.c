#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

typedef int (*get_hash_t)(const char *s);

int ncollisions(char **strs, int n, get_hash_t f);


int main() {
    return 0;
}
