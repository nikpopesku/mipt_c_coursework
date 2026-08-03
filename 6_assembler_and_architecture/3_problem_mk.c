#include <stdio.h>

enum Register {
    A = 0,
    B = 1,
    C = 2,
    D = 3
};

int main() {
    unsigned val;
    int A, B, C, D;
    enum Register first;
    enum Register second;

    while (scanf("%x", &val) == 1) {
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
