#include <assert.h>
#include <stdio.h>

long long ee_gcd(long long koef[1000][4])
{
    long long index = 1;

    while (koef[index - 2][0] % koef[index - 1][0] != 0)
    {
        ++index;
        koef[index][0] = koef[index - 2][0] % koef[index - 1][0];
        koef[index][1] = koef[index - 2][0] / koef[index - 1][0];
        koef[index][2] = koef[index - 2][2] - koef[index][1] * koef[index - 1][2];
        koef[index][3] = koef[index - 2][3] - koef[index][1] * koef[index - 1][3];
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

    koef[0][0] = x;
    koef[0][2] = 1;
    koef[0][3] = 0;
    koef[1][0] = y;
    koef[1][2] = 0;
    koef[1][3] = 1;

    const long long index = ee_gcd(koef);

    printf("%lld %lld %lld", koef[index][2], koef[index][3], koef[index][0]);
}
