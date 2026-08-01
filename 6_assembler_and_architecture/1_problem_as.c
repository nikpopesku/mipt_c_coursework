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
    regmatch_t matches[3];
    regex_t vals[2];

    int res = regcomp(&re_movi, "^(MOVI) ([0-9]+)$", REG_EXTENDED);
    assert(res == 0);
    res = regcomp(&re_out, "^(OUT) ([A-D]{1})$", REG_EXTENDED);
    assert(res == 0);

    vals[0] = re_movi;
    vals[1] = re_out;


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


        if (regexec(&re_movi, buf, 3, matches, 0) == 0) {
            regmatch_t g1 = matches[1];
            regmatch_t g2 = matches[2];

            for (i = g1.rm_so; i < g1.rm_eo; ++i) printf("%c", buf[i]);
            for (i = g2.rm_so; i < g2.rm_eo; ++i) printf("%c", buf[i]);
            printf("\n");
        }
    } while (len > 0);

    regfree(&re_movi);
    regfree(&re_out);
    free(buf);

    return 0;
}
