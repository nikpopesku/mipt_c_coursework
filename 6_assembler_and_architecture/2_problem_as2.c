#include <assert.h>
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
    unsigned val;
    enum Register first;
    enum Register second;

    while (scanf("%x", &val) == 1) {
        if (val >> 7 == 0) {
            printf("MOVI %d\n", val);
            continue;
        }

        first = (val & (3 << 2)) >> 2;
        second = val & 3;

        switch (val >> 4) {
            case 8:
                printf("ADD %c, %c\n", first, second);
                break;
            case 9:
                printf("SUB %c, %c\n", first, second);
                break;
            case 10:
                printf("MUL %c, %c\n", first, second);
                break;
            case 11:
                printf("DIV %c, %c\n", first, second);
                break;
            case 12:
                if ((val & (1 << 3) >> 3) == 1) {
                    printf("OUT %c\n", second);
                } else {
                    printf("IN %c\n", second);
                }
        }

    }
    return 0;
}
