#include <assert.h>
#include <stdio.h>
#include <stdlib.h>


int main() {
    unsigned sz1, sz2, i;
    char *needle, *haystack;
    int res = scanf("%u", &sz1);
    assert(res == 1);

    needle = calloc(sz1, sizeof(char));

    for (i = 0; i < sz1; ++i) {
        res = scanf("%c", &needle[i]);
        assert(res == 1);
    }

    res = scanf("%u", &sz2);
    assert(res == 1);

    haystack = calloc(sz2, sizeof(char));

    for (i = 0; i < sz2; ++i) {
        res = scanf("%c", &haystack[i]);
        assert(res == 1);
    }


    return 0;
}
