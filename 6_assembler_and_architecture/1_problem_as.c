#include <assert.h>
#include <regex.h>
#include <stdio.h>
#include <stdlib.h>

int main() {
    char ch;
    size_t cap = 16, len = 0;
    char *buf = calloc(cap, sizeof(char)), *new_buf;

    regex_t re;
    int ret = regcomp(&re, "^[a-zA-Z0-9._%+-]+@[a-zA-Z0-9.-]+\\.[a-zA-Z]{2,}$", REG_EXTENDED);
    assert(ret == 0);

    while ((ch = getchar()) != EOF && ch != '\n') {
        if (len + 1 >= cap) {
            cap *= 2;
            new_buf = realloc(buf, cap);
            buf = new_buf;
            assert(buf != NULL);
        }
        buf[len++] = ch;
    }

    buf[len] = '\0';


    return 0;
}
