#include <assert.h>
#include <regex.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char ch;
    size_t cap = 16, len = 0;
    char *buf, *new_buf;
    unsigned i;

    regex_t re_movi, re_out;
    regmatch_t matches[2];
    int res = regcomp(&re_movi, "^MOVI ([0-9]+)$", REG_EXTENDED);
    assert(res == 0);
    res = regcomp(&re_out, "^OUT ([A-D]{1})$", REG_EXTENDED);
    assert(res == 0);

    do {
        len = 0;
        cap = 16;
        buf = calloc(cap, sizeof(char));

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


        if (regexec(&re_movi, buf, 2, matches, 0) == 0) {
            regmatch_t g = matches[1];

            printf("MOVI ");
            for (i = g.rm_so; i < g.rm_eo; ++i) {
                printf("%c", buf[i]);
            }
            printf("\n");
        }
        if (regexec(&re_out, buf, 2, matches, 0) == 0) {
            regmatch_t g = matches[1];

            printf("OUT ");
            for (i = g.rm_so; i < g.rm_eo; ++i) {
                printf("%c", buf[i]);
            }
            printf("\n");
        }
    } while (len > 0);

    regfree(&re_movi);
    regfree(&re_out);
    free(buf);

    return 0;
}
