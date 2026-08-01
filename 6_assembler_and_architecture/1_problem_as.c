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

enum Opcode {
    OP_ADD = 8,
    OP_SUB = 9,
    OP_MUL = 10,
    OP_DIV = 11
};


int main() {
    char ch;
    size_t cap = 16, len = 0;
    char *buf = NULL, *new_buf;
    unsigned val;
    enum Register reg;

    regex_t re_movi, re_out, re_in, re_add, re_sub, re_mul, re_div;
    regmatch_t matches[5];
    unsigned k;
    int matched, first_token = 1;

    struct {
        regex_t *re;
        enum Opcode op;
    } two_op[] = {
        {&re_add, OP_ADD},
        {&re_sub, OP_SUB},
        {&re_mul, OP_MUL},
        {&re_div, OP_DIV},
    };

    struct {
        regex_t *re;
        unsigned base;
    } one_op[] = {
        {&re_in, 0xC0},
        {&re_out, 0xC4},
    };

    regcomp(&re_movi, "^(MOVI) ([0-9]+)$", REG_EXTENDED);
    regcomp(&re_out, "^(OUT) ([A-D]{1})$", REG_EXTENDED);
    regcomp(&re_in, "^(IN) ([A-D]{1})$", REG_EXTENDED);
    regcomp(&re_add, "^(ADD) ([A-D]{1})(,[[:space:]]?)([A-D]{1})$", REG_EXTENDED);
    regcomp(&re_sub, "^(SUB) ([A-D]{1})(,[[:space:]]?)([A-D]{1})$", REG_EXTENDED);
    regcomp(&re_mul, "^(MUL) ([A-D]{1})(,[[:space:]]?)([A-D]{1})$", REG_EXTENDED);
    regcomp(&re_div, "^(DIV) ([A-D]{1})(,[[:space:]]?)([A-D]{1})$", REG_EXTENDED);

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

        if (len == 0) {
            free(buf);
            break;
        }

        matched = 0;

        if (regexec(&re_movi, buf, 3, matches, 0) == 0) {
            regmatch_t g2 = matches[2];
            val = strtoul(buf + g2.rm_so, NULL, 10) & 0x7F;
            matched = 1;
        } else {
            for (k = 0; k < 2; ++k) {
                if (regexec(one_op[k].re, buf, 3, matches, 0) == 0) {
                    regmatch_t g2 = matches[2];
                    reg = buf[g2.rm_so] - 'A';
                    val = one_op[k].base | reg;
                    matched = 1;
                    break;
                }
            }
        }

        if (!matched) {
            for (k = 0; k < 4; ++k) {
                if (regexec(two_op[k].re, buf, 5, matches, 0) == 0) {
                    regmatch_t g2 = matches[2];
                    regmatch_t g4 = matches[4];
                    val  = two_op[k].op << 4;
                    reg = buf[g2.rm_so] - 'A';
                    val = val + (reg << 2);
                    val = val + (buf[g4.rm_so] - 'A');
                    matched = 1;
                    break;
                }
            }
        }

        if (matched) {
            printf(first_token ? "0x%x" : " 0x%x", val);
            first_token = 0;
        } else {
            printf(first_token ? "ERROR" : " ERROR");
            free(buf);
            break;
        }

        free(buf);
    } while (len > 0);

    printf("\n");

    regfree(&re_movi);
    regfree(&re_out);
    regfree(&re_in);
    regfree(&re_add);
    regfree(&re_sub);
    regfree(&re_mul);
    regfree(&re_div);

    return 0;
}
