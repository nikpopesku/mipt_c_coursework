#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    unsigned sz1, sz2;
    int i, j;
    char *word;
    char *sentence;
    char *result;
    char *pos;

    int res = scanf("%u", &sz1);
    assert(res == 1);

    getchar();

    word = calloc(sz1 + 1, sizeof(char));
    for (i = 0; i < sz1; ++i) {
        word[i] = getchar();
    }

    res = scanf("%u", &sz2);
    assert(res == 1);

    getchar();


    sentence = calloc(sz2 + 1, sizeof(char));
    for (i = 0; i < sz2; ++i) {
        sentence[i] = getchar();
    }

    for (i = 0, j = sz1 - 1; i < j; ++i, --j) {
        if (word[i] != word[j]) {
            break;
        }
    }

    if (word[i] != word[j]) {
        pos = sentence;
        while ((result = strstr(pos, word))) {
            pos = result + sz1;
            for (i = sz1 - 1; i >= 0; --i, result++) {
                *result = word[i];
            }
        }
    }

    for (i = 0; i < sz2; ++i) {
        printf("%c", sentence[i]);
    }

    return 0;
}
