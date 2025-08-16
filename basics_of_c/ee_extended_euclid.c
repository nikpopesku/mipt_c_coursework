#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

long long ee_gcd(long long koef[1000][4])
{
    long long index = 2;

    while (koef[index - 2][0] % koef[index - 1][0] != 0)
    {
        koef[index][0] = koef[index - 2][0] % koef[index - 1][0];
        koef[index][1] = koef[index - 2][0] / koef[index - 1][0];
        koef[index][2] = koef[index - 2][2] - koef[index][1] * koef[index - 1][2];
        koef[index][3] = koef[index - 2][3] - koef[index][1] * koef[index - 1][3];
        ++index;
    }

    return index - 1;
}

int main()
{
    long long x = 0, y = 0;

    const int res = scanf("%lld %lld", &x, &y);
    assert(res == 2);

    long long koef[1000][4];
    koef[0][0] = llabs(x);
    koef[0][2] = 1;
    koef[0][3] = 0;
    koef[1][0] = llabs(y);
    koef[1][2] = 0;
    koef[1][3] = 1;

    const long long index = ee_gcd(koef);
    const long long a = x < 0 ? -koef[index][2] : koef[index][2];
    const long long b = y < 0 ? -koef[index][3] : koef[index][3];
    const long long gcd = koef[index][0];

    printf("%lld %lld %lld", a, b, gcd);
}
