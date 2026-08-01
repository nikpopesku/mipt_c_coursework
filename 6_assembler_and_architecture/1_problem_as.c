#include <assert.h>
#include <regex.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char ch;
    size_t cap = 16, len = 0;
    char *buf = calloc(cap, sizeof(char)), *new_buf;
    unsigned i;

    regex_t re;
    regmatch_t matches[2];
    int ret = regcomp(&re, "^MOVI ([0-9]+)$", REG_EXTENDED);
    assert(ret == 0);

    do {
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


        if (regexec(&re, buf, 2, matches, 0) == 0) {
            regmatch_t g = matches[1];

            printf("MOVI ");
            for (i = g.rm_so; i < g.rm_eo; ++i) {
                printf("%c", buf[i]);
            }
        }
    } while (buf != NULL);

    regfree(&re);
    free(buf);

    return 0;
}
