#include <assert.h>
#include <stdio.h>

int main()
{
    int a, b, n;

    const int res = scanf("%d %d %d", &a, &b, &n);
    assert(res == 3);
}
