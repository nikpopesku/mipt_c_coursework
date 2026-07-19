#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *strcat_r(char *dest, const char *src, int *bufsz) {
    int i, j;
    for (i = 0; i < *bufsz && dest[i] != '\0'; ++i) {}
    for (j = 0; src[i] != '\0'; ++j) {}
    if (i + j > *bufsz) {
        realloc(dest, i + j);
    }
}


int main() {
    return 0;
}
