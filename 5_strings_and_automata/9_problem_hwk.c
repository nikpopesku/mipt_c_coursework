#include <assert.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "func.h"

void patpreproc(char const *needle, int *needle_lps) {
    int i, j;

    for (i = 1; i < strlen(needle); ++i) {
        j = needle_lps[i - 1];

        while (j > 0 && tolower(needle[i]) != tolower(needle[j])) {
            j = needle_lps[j - 1];
        }

        needle_lps[j] = j + (tolower(needle[i]) == tolower(needle[j]) ? 1 : 0);
    }
}

char *strstrci(char const *needle, int const *needle_lps, char const *haystack) {
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
    unsigned sz1, sz2, i;
    char *haystack, *needle;
    int res = scanf("%u", &sz1);
    int *needle_lps;
    assert(res == 1);

    getchar();

    haystack = calloc(sz1 + 1, sizeof(char));
    for (i = 0; i < sz1; ++i) {
        res = scanf("%c", &haystack[i]);
        assert(res == 1);
    }

    haystack[i] = '\0';

    getchar();

    res = scanf("%u", &sz2);
    assert(res == 1);

    getchar();

    needle = calloc(sz2 + 1, sizeof(char));
    for (i = 0; i < sz2; ++i) {
        res = scanf("%c", &needle[i]);
        assert(res == 1);
    }

    needle[i] = '\0';

    needle_lps = calloc(strlen(needle), sizeof(int));
    patpreproc(needle, needle_lps);

    free(needle_lps);
    free(needle);
    free(haystack);


    return 0;
}
