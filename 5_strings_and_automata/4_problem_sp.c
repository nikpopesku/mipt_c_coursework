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
}

int main() {
    return 0;
}
