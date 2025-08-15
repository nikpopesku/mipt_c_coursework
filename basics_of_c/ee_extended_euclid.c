#include <assert.h>
#include <stdio.h>

unsigned long long ee_gcd(long long x, long long y, long long remainder[], long long coefficient[])
{
    if (x < 0) x = -x;
    if (y < 0) y = -y;
    long long index = 0;

    while (y != x)
    {
        if (y > x)
        {
            coefficient[index] = y / x;
            y = y - x * coefficient[index];
            remainder[index] = y;
        }
        else
        {
            coefficient[index] = x / y;
            remainder[index] = x - y * coefficient[index];
        }
        ++index;
    }

    return y;
}

int main()
{
    long long x = 0, y = 0;

    const int res = scanf("%lld %lld", &x, &y);
    assert(res == 2);

    long long remainder[1000];
    long long coefficient[1000];

    const long long g = ee_gcd(x, y, remainder, coefficient);
    printf("%llu\n", g);
    return 0;
}
