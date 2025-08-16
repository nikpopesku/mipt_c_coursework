#include <assert.h>
#include <stdio.h>

long long ee_gcd(long long x, long long y, long long koef[1000][4])
{
    long long index = 0;

    while (y != x)
    {
        if (y > x)
        {
            numerator[index] = y;
            coefficient[index] = y / x;
            y = y - x * coefficient[index];
            remainder[index] = y;

        }
        else
        {
            numerator[index] = x;
            coefficient[index] = x / y;
            remainder[index] = x - y * coefficient[index];
        }
        ++index;
    }

    return index;
}

int main()
{
    long long x = 0, y = 0;

    const int res = scanf("%lld %lld", &x, &y);
    assert(res == 2);

    long long koef[1000][4];
    if (x < 0) x = -x;
    if (y < 0) y = -y;
    if (x < y)
    {
        const long long tmp = x;
        x = y;
        y = tmp;
    }

    koef[0][0] = x; koef[0][2]= 1; koef[0][3] = 0;
    koef[1][0] = y; koef[1][2] = 0; koef[1][3] = 1;

    const long long g = ee_gcd(x, y, koef);

    printf("%llu\n", g);
    return 0;
}
