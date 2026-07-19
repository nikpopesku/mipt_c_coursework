#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *replace(char *str, char const *from, char const *to) {
    char *p, *new_str, *prev, *cur;
    char *source = str;
    int i, count = 0, k = 0;

    if (strlen(from) != strlen(to)) {
        while ((p = strstr(source, from)) != NULL) {
            ++count;
            source = p + strlen(to);
        }
    }

    new_str = calloc(strlen(str) + count * (strlen(from) - strlen(to)) + 1, sizeof(char));

    source = str;
    prev = source;

    while ((p = strstr(source, from)) != NULL) {
        for (cur = prev; cur < p; ++cur) {
            new_str[k++] = *cur;
        }

        for (i = 0; i < strlen(to); ++i) {
            new_str[k++] = to[i];
        }

        source = p + strlen(from);
    }

    return new_str;
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
