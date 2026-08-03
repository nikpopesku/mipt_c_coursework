#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

enum Register {
    A = 0,
    B = 1,
    C = 2,
    D = 3
};

int main() {
    unsigned val, counter = 0;
    unsigned A, B, C, D;
    size_t cap = 16, len = 0;
    size_t cap_num = 16, len_num = 0;
    char *buf = calloc(cap, sizeof(char)), *new_buf;
    char *buf_num = calloc(cap, sizeof(char)), *new_buf_num;
    enum Register first;
    enum Register second;

    while (scanf("%x", &val) == 1 && val != 240) {
        if (len + 1 >= cap) {
            cap *= 2;
            new_buf = realloc(buf, cap);
            buf = new_buf;
            assert(buf != NULL);
        }
        buf[len++] = val;
    }

    while (scanf("%u", &val) == 1) {
        if (len_num + 1 >= cap_num) {
            cap *= 2;
            new_buf_num = realloc(buf_num, cap_num);
            buf_num = new_buf_num;
            assert(buf_num != NULL);
        }
        buf_num[len_num++] = val;
    }

    for (counter = 0; counter < len; ++counter) {
        val = buf[counter];
        if (val >> 7 == 0) {
            D = val;
            continue;
        }

        first = (val & (3 << 2)) >> 2;
        second = val & 3;

        switch (val >> 4) {
            case 8:
                printf("ADD %c, %c\n", 'A' + first, 'A' + second);
                break;
            case 9:
                printf("SUB %c, %c\n", 'A' + first, 'A' + second);
                break;
            case 10:
                printf("MUL %c, %c\n", 'A' + first, 'A' + second);
                break;
            case 11:
                printf("DIV %c, %c\n", 'A' + first, 'A' + second);
                break;
            case 12:
                if ((val & (1 << 2)) >> 2 == 1) {
                    printf("OUT %c\n", 'A' + second);
                } else {
                    printf("IN %c\n", 'A' + second);
                }
                break;
            default:
                printf("ERROR\n");
                return 0;
        }

    }
    return 0;
}
