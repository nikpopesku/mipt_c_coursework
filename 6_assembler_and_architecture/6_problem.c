#include <assert.h>
#include <stdio.h>

#include "start.h"

int main() {
    unsigned x;
    int res = scanf("%u", &x);
    assert(res == 1);

    printf("%d\n", start(x));
}