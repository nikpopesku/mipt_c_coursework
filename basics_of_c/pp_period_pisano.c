#include <assert.h>
#include <stdio.h>

int solve(const int x, const int m)
{
}

int main()
{
    unsigned int x, m;

    const int res = scanf("%u %u", &x, &m);
    assert(res == 2);

    const int response = solve(x, m);
    printf("%d", response);

    return 0;
}
