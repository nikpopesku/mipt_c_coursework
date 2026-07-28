#include <assert.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>
#include "func.h"

void patpreproc(char const * needle, int * needle_lps) {

}

char * strstrci(char const * needle, int const * needle_lps, char const * haystack) {
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
    return 0;
}
