#include <assert.h>
#include <stdio.h>

void solve(const int long long x, const int long long m)
{
    int long long pisano_period = 0;
    int long long counter = 1;
    int long long last = 0;
    int long long penultimate = 1 % m;
    int long long value = 0;
    int long long fib_response = 0;

    do
    {
        ++counter;
        value = (penultimate + last) % m;
        last = penultimate;
        penultimate = value;
    }
    while (penultimate != 1 || last != 0);

    pisano_period = counter - 1;

    if (x % pisano_period == 0)
    {
        fib_response = 0;
    }
    else if (x % pisano_period == 1)
    {
        fib_response = 1;
    }
    else
    {
        for (int long long i = 2; i <= x % pisano_period; ++i)
        {
            value = (penultimate + last) % m;
            last = penultimate;
            penultimate = value;
        }

        fib_response = value;
    }

    printf("%lld %lld", fib_response, pisano_period);
}

int main()
{
    int long long x = 0, m = 0;

    const int res = scanf("%lld %lld", &x, &m);
    assert(res == 2);

    solve(x, m);

    return 0;
}
