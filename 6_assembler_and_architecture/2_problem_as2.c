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


    }
    return 0;
}
