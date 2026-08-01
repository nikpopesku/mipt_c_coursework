#include <assert.h>
#include <regex.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char ch;
    size_t cap = 16, len = 0;
    char *buf, *new_buf;
    unsigned i, j;

    regex_t re_movi, re_out, re_in, re_add, re_sub, re_mul, re_div;
    regmatch_t matches[5];
    regex_t re_arr[7];

    regcomp(&re_movi, "^(MOVI )([0-9]+)$", REG_EXTENDED);
    regcomp(&re_out, "^(OUT )([A-D]{1})$", REG_EXTENDED);
    regcomp(&re_in, "^(IN )([A-D]{1})$", REG_EXTENDED);
    regcomp(&re_add, "^(ADD )([A-D]{1})(,[[:space:]]?)([A-D]{1})$", REG_EXTENDED);
    regcomp(&re_sub, "^(SUB )([A-D]{1})(,[[:space:]]?)([A-D]{1})$", REG_EXTENDED);
    regcomp(&re_mul, "^(MUL )([A-D]{1})(,[[:space:]]?)([A-D]{1})$", REG_EXTENDED);
    regcomp(&re_div, "^(DIV )([A-D]{1})(,[[:space:]]?)([A-D]{1})$", REG_EXTENDED);

    re_arr[0] = re_movi;
    re_arr[1] = re_out;
    re_arr[2] = re_in;
    re_arr[3] = re_add;
    re_arr[4] = re_sub;
    re_arr[5] = re_mul;
    re_arr[6] = re_div;


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


        for (i = 0; i < 7; ++i) {
            if (regexec(&re_arr[i], buf, 5, matches, 0) == 0) {
                regmatch_t g1 = matches[1];
                regmatch_t g2 = matches[2];
                regmatch_t g3 = matches[3];
                regmatch_t g4 = matches[4];

                for (j = g1.rm_so; j < g1.rm_eo; ++j) printf("%c", buf[j]);
                for (j = g2.rm_so; j < g2.rm_eo; ++j) printf("%c", buf[j]);
                for (j = g3.rm_so; j < g3.rm_eo; ++j) printf("%c", buf[j]);
                for (j = g4.rm_so; j < g4.rm_eo; ++j) printf("%c", buf[j]);
                printf("\n");
            }
        }
    } while (len > 0);

    regfree(&re_movi);
    regfree(&re_out);
    regfree(&re_in);
    regfree(&re_add);
    regfree(&re_sub);
    regfree(&re_mul);
    regfree(&re_div);
    free(buf);

    return 0;
}
