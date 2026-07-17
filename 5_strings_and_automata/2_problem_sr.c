#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

int main() {
    unsigned sz1, sz2;
    unsigned i;
    char * word;
    char * sentence;
    int res = scanf("%d", &sz1);
    assert(res == 1);

    word = calloc(sz1 + 1, sizeof(char));
    for (i = 0; i < sz1; ++i) {
        word[i] = getchar();
    }

    res = scanf("%d", &sz2);
    assert(res == 1);

    sentence = calloc(sz2 + 1, sizeof(char));
    for (i = 0; i < sz2; ++i) {
        sentence[i] = getchar();
    }

    return 0;
}
