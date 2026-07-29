#include <assert.h>
#include <ctype.h>
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
    unsigned i = 0;
    int j = 0;
    size_t needle_len = strlen(needle);
    size_t haystack_len = strlen(haystack);

    if (haystack_len < needle_len) return NULL;

    for (i = 0; i < haystack_len; ++i) {

        while (j > 0 && tolower(haystack[i]) != tolower(needle[j])) {
            j = needle_lps[j - 1];
        }

        if (tolower(haystack[i]) == tolower(needle[j])) {
            ++j;
        }

        if (j == needle_len) {
            return (char *) (haystack + i - needle_len + 1);
        }
    }

    return NULL;
}
