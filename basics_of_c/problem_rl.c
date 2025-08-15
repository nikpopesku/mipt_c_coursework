#include <assert.h>
#include <stdio.h>

unsigned long long gcd(long long x, long long y)
{
    if (x < 0) x = -x;
    if (y < 0) y = -y;

    while (y != x)
    {
        if (y > x)
        {
            y -= x;
        }
        else
        {
            x -= y;
        }
    }

    return y;
}

int main()
{
    long long x = 0, y = 0, g;

    const int res = scanf("%lld %lld", &x, &y);
    assert(res == 2);
    g = gcd(x, y);
    printf("%llu\n", g);
    return 0;
}
