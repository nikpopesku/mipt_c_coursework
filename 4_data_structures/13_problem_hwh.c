#include <assert.h>
#include <stdio.h>
#include <stdlib.h>


int main() {
    unsigned answer;
    unsigned sz1;
    unsigned sz2;
    unsigned i = 0;
    char word[100];
    char ch;
    // int * arr = calloc(26, siz)
    int res = scanf("%u", &answer);
    assert(res == 1);

    res = scanf("%u", &sz1);
    assert(res == 1);


    while (i < sz1) {
        ch = getchar();
        if (ch == ' ' || ch == '\n' || ch == EOF) {

        }
    }



    return 0;
}
