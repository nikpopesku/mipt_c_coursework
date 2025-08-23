#include <assert.h>
#include <stdio.h>

void solve(const int long long x, const int long long m)
{
    int long long pisano_period = 0;
    int long long counter = 1;
    int long long fib[1000000];
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
    int long long x = 0, m = 0;

    const int res = scanf("%lld %lld", &x, &m);
    assert(res == 2);

    solve(x, m);

    return 0;
}
