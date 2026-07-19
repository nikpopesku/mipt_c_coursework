#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *replace(char *str, char const *from, char const *to) {
    char *p;
    char *source = str;
    int i;


    while ((p = strstr(source, from)) != NULL) {
        for (i = 0; to[i] != '\0'; ++i) {
            p[i] = to[i];
        }

        source = p + i;
    }

    return str;
}

int main() {
    unsigned sz1, sz2, sz3, i = 0;
    char ch;
    char *from, *to, *src;
    int res = scanf("%u", &sz1);
    assert(res == 1);

    from = calloc(sz1 + 1, sizeof(char));
    getchar();

    while ((ch = getchar()) != '\n') {
        from[i++] = ch;
    }
    from[i] = '\0';

    res = scanf("%u", &sz2);
    assert(res == 1);

    i = 0;
    to = calloc(sz2 + 1, sizeof(char));
    getchar();

    while ((ch = getchar()) != '\n') {
        to[i++] = ch;
    }
    to[i] = '\0';


    res = scanf("%u", &sz3);
    assert(res == 1);

    i = 0;
    src = calloc(sz3 + 1, sizeof(char));
    getchar();

    while ((ch = getchar()) != '\n') {
        src[i++] = ch;
    }
    src[i] = '\0';

    src = replace(src, from, to);

    for (i = 0; src[i] != '\0'; ++i) {
        printf("%c", src[i]);
    }

    return 0;
}
