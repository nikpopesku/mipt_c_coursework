#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <regex.h>

int main() {
    unsigned sz1, sz2, i;
    char *needle, *haystack;
    regex_t re;
    regmatch_t match;
    int res = scanf("%u", &sz1);
    assert(res == 1);

    getchar();

    needle = calloc(sz1 + 1, sizeof(char));

    for (i = 0; i < sz1; ++i) {
        res = scanf("%c", &needle[i]);
        assert(res == 1);
    }

    needle[i] = '\0';

    getchar();

    res = scanf("%u", &sz2);
    assert(res == 1);

    getchar();

    haystack = calloc(sz2 + 1, sizeof(char));

    for (i = 0; i < sz2; ++i) {
        res = scanf("%c", &haystack[i]);
        assert(res == 1);
    }

    haystack[i] = '\0';

    res = regcomp(&re, needle, REG_EXTENDED);
    assert(res == 0);

    while (regexec(&re, haystack, 1, &match, 0) != 0) {
        res = 2;
    }

    return 0;
}
