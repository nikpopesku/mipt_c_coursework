#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <regex.h>

int main() {
    unsigned sz1, sz2, i, j, offset;
    char *needle, *haystack, *word;
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

    offset = 0;
    while (regexec(&re, haystack + offset, 1, &match, 0) == 0) {
        word = calloc(match.rm_eo - match.rm_so + 1, sizeof(char));
        for (i = offset + match.rm_eo - 1, j = 0; i >= offset + match.rm_so; --i, ++j) {
            word[j] = haystack[i];
        }

        word[match.rm_eo - match.rm_so] = '\0';

        for (i = offset + match.rm_so; i < offset + match.rm_eo; ++i, ++j) {
            haystack[i] = word[i - offset - match.rm_so];
        }

        offset += match.rm_eo;
    }

    for (i = 0; i < sz2; ++i) {
        printf("%c", haystack[i]);
    }

    printf("\n");

    return 0;
}
