#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    unsigned val;

    while (scanf("%x", &val) == 1) {
        if (val >> 7 == 0) {
            printf("MOVI %d\n", val);
            continue;
        }

        switch (val >> 4) {
            case 8:
                printf("ADD ");
                break;
            case 9:
                printf("SUB ");
                break;
            case 10:
                printf("MUL ");
                break;
            case 11:
                printf("DIV ");
                break;
            case 12:
                if ((val & (1 << 3)) == 1) {
                    printf("OUT ");
                } else {
                    printf("IN ");
                }
        }

    }
    return 0;
}
