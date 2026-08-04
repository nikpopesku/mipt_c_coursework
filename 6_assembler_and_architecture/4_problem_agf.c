#include <assert.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

int foo(int x, int y) {
    int eax, edx;
    int edi = x;
    int esi = y;
    eax = edi;
    eax = eax * edi * edi;

    if (eax < 0) {
        esi = esi * esi;
        edi = edi + edi;
        edx = 17;
        edx = edx - edi;
        edx = edx - esi;
        eax = eax + edx;

        return eax;
    }

    return eax;
}


int main() {
    return 0;
}
