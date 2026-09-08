#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    unsigned cell_count, queries_count;
    int res = scanf("%u", &cell_count);
    assert(res == 1);

    res =  scanf("%u", &queries_count);
    assert(res == 1);

    return 0;
}
