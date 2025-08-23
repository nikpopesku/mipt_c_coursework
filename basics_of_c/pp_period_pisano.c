#include <assert.h>
#include <stdio.h>

void solve(const int x, const int m)
{
    int pisano_period = 0;
    int counter = 1;
    int fib[100000];
    fib[0] = 0;
    fib[1] = 1 % m;
    fib[2] = 0;

    do
    {
        fib[++counter] = (fib[counter] + fib[counter - 1]) % m;
    }
    while (fib[counter] != 1 || fib[counter - 1] != 0);

    pisano_period = counter - 1;

    printf("%d %d", fib[x % pisano_period], pisano_period);
}

int main()
{
    int x = 0, m = 0;

    const int res = scanf("%d %d", &x, &m);
    assert(res == 2);

    solve(x, m);

    return 0;
}
