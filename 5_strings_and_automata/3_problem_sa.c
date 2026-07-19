#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *strcat_r(char *dest, const char *src, int *bufsz) {
    int i, j, k;
    for (i = 0; i < *bufsz && dest[i] != '\0'; ++i) {
    }
    for (j = 0; src[j] != '\0'; ++j) {
    }
    if (i + j + i > *bufsz) {
        dest = realloc(dest, i + j + 1);
        *bufsz = i + j + 1;
    }

    for (k = 0; k < j; ++k) {
        dest[k + i] = src[k];
    }
    dest[k + i] = '\0';

    return dest;
}


int main() {
    unsigned i = 0;
    char *src, *dest;
    char ch;
    int sz, *ptr_sz;

    int res = scanf("%d", &sz);
    assert(res == 1);

    getchar();

    dest = calloc(sz, sizeof(char));

    while ((ch = getchar()) != '\n') {
        dest[i++] = ch;
    }
    dest[i] = '\0';

    i = 0;
    src = calloc(8, sizeof(char));

    while ((ch = getchar()) != '\n') {
        src[i++] = ch;
    }
    src[i] = '\0';


    ptr_sz = &sz;
    strcat_r(dest, src, ptr_sz);

    for (i = 0; dest[i] != '\0'; ++i) {
        printf("%c", dest[i]);
    }


    return 0;
}
