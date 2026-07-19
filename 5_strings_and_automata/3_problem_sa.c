#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *strcat_r(char *dest, const char *src, int *bufsz) {
    int i, j, k;
    for (i = 0; i < *bufsz && dest[i] != '\0'; ++i) {
    }
    for (j = 0; src[i] != '\0'; ++j) {
    }
    if (i - 1 + j > *bufsz) {
        realloc(dest, i + j - 1);
        *bufsz = i + j - 1;
    }

    for (k = 0; k < j; ++k) {
        dest[k + i - 1] = src[k];
    }

    return dest;
}


int main() {
    unsigned sz;
    int res = scanf("%u", &sz);
    assert(res == 1);


    return 0;
}
