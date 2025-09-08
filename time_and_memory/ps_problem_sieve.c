#include "u_template.h"
#include <stdio.h>
#include <assert.h>

int solve(int n)
{
    return n + 2;
}

int main()
{
    int n = 0;

    const int res = scanf("%d", &n);
    assert(res == 1);

    const int number = solve(n);

    printf("%d", number);

    return 0;
}