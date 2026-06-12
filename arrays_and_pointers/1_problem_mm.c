#include <assert.h>
#include <stdio.h>

int main()
{
    int sz;
    const int res = scanf("%d", &sz);
    assert(res == 1);

    if (sz == 0) {
        printf("0 0");

        return 0;
    }

    for (int i = 0; i < sz; ++i) {

    }

    return 0;
}
