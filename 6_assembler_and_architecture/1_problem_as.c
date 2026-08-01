#include <assert.h>
#include <regex.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

enum Register {
    A = 0,
    B = 1,
    C = 2,
    D = 3
};


int main() {
    char ch;
    size_t cap = 16, len = 0;
    char *buf = NULL, *new_buf;
    unsigned val;
    enum Register reg;

    regex_t re_movi, re_out, re_in, re_add, re_sub, re_mul, re_div;
    regmatch_t matches[5];
    // regex_t re_arr[4];

    regcomp(&re_movi, "^(MOVI) ([0-9]+)$", REG_EXTENDED);
    regcomp(&re_out, "^(OUT) ([A-D]{1})$", REG_EXTENDED);
    regcomp(&re_in, "^(IN) ([A-D]{1})$", REG_EXTENDED);
    regcomp(&re_add, "^(ADD) ([A-D]{1})(,[[:space:]]?)([A-D]{1})$", REG_EXTENDED);
    regcomp(&re_sub, "^(SUB) ([A-D]{1})(,[[:space:]]?)([A-D]{1})$", REG_EXTENDED);
    regcomp(&re_mul, "^(MUL) ([A-D]{1})(,[[:space:]]?)([A-D]{1})$", REG_EXTENDED);
    regcomp(&re_div, "^(DIV) ([A-D]{1})(,[[:space:]]?)([A-D]{1})$", REG_EXTENDED);

    // re_arr[0] = re_movi;
    // re_arr[1] = re_out;
    // re_arr[2] = re_in;
    // re_arr[0] = re_add;
    // re_arr[1] = re_sub;
    // re_arr[2] = re_mul;
    // re_arr[3] = re_div;


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


        if (regexec(&re_add, buf, 5, matches, 0) == 0) {
            regmatch_t g2 = matches[2];
            regmatch_t g4 = matches[4];
            val  = 8 << 4;
            reg = buf[g2.rm_so];
            val = val + (reg << 2);
            val = val + buf[g4.rm_so];
            printf("%x", val);
        }

        free(buf);
    } while (len > 0);

    regfree(&re_movi);
    regfree(&re_out);
    regfree(&re_in);
    regfree(&re_add);
    regfree(&re_sub);
    regfree(&re_mul);
    regfree(&re_div);

    return 0;
}
