#include <assert.h>
#include <ctype.h>
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
}

int main() {
    unsigned sz1, sz2, i = 0;
    char ch;
    char *from, *to;
    int res = scanf("%u", &sz1);
    assert(res == 1);

    from = calloc(sz1, sizeof(char));

    while ((ch = getchar()) != '\n') {
        from[i++] = ch;
    }
    from[i] = '\0';

    res = scanf("%u", &sz2);
    assert(res == 1);

    i = 0;
    to = calloc(sz2, sizeof(char));

    while ((ch = getchar()) != '\n') {
        to[i++] = ch;
    }
    to[i] = '\0';

    return 0;
}
