#include <assert.h>
#include <stdio.h>
#include <stdlib.h>


int main() {
    char ch, *p;
    size_t cap = 16, len = 0;
    char *buf = calloc(cap, sizeof(char)), *new_buf;

    while ((ch = getchar()) != EOF && ch != '\n') {
        if (len + 1 >= cap) {
            cap *= 2;
            new_buf = realloc(buf, cap);
            buf = new_buf;
            assert(buf != NULL);
        }
        buf[len++] = (char) ch;
    }
    return 0;
}
