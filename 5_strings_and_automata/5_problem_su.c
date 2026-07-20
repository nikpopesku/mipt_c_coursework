#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

char *strstrci(char const *needle, char const *haystack) {
    unsigned i = 0, j = 0;

    if (strlen(haystack) < strlen(needle)) return NULL;

    for (i = 0; i < strlen(haystack) - strlen(needle); ++i) {
        if (tolower(haystack[i]) != tolower(needle[0])) continue;

        if (strlen(needle) == 1) return (char *) (haystack + i);

        for (j = 1; j < strlen(needle) && j + i < strlen(haystack) && tolower(haystack[j + i]) == tolower(needle[j]); ++
             j) {
        }

        if (j == strlen(needle)) {
            return (char *) (haystack + i);
        }
    }

    return NULL;
}


int main() {
    unsigned sz1, i, sz2;
    char *haystack, *needle, *new_haystack;
    int res = scanf("%u", &sz1);
    assert(res == 1);

    getchar();

    haystack = calloc(sz1 + 1, sizeof(char));

    for (i = 0; i < sz1; ++i) {
        res = scanf("%c", &haystack[i]);
        assert(res == 1);
    }
    haystack[i] = '\0';

    res = scanf("%u", &sz2);
    assert(res == 1);

    getchar();

    needle = calloc(sz2 + 1, sizeof(char));

    for (i = 0; i < sz2; ++i) {
        res = scanf("%c", &needle[i]);
        assert(res == 1);
    }
    needle[i] = '\0';

    new_haystack = strstrci(needle, haystack);


    for (i = 0; i < strlen(new_haystack); ++i) {
        printf("%c", new_haystack[i]);
    }

    free(haystack);
    free(needle);

    return 0;
}
