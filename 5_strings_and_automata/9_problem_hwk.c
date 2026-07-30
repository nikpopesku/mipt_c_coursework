#include <assert.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "func.h"

void patpreproc(char const *needle, int *needle_lps) {
}

char *strstrci(char const *needle, int const *needle_lps, char const *haystack) {
}

int main() {
    unsigned sz1, sz2, i;
    char *haystack, *needle, *pos;
    int res = scanf("%u", &sz1);
    int *needle_lps, counter;
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



    // free(needle_lps);
    free(needle);
    free(haystack);



    return 0;
}
