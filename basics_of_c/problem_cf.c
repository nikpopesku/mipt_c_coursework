#include <assert.h>
#include <stdio.h>

long long calc(long long x, long long y, long long response[])
{
    long long index = -1;

    while (x % y != 0)
    {
        response[++index] = x / y;
        const long long tmp = response[index] > 0 ? x - response[index] * y : x;
        x = y;
        y = tmp;
    }

    response[++index] = x / y;

    return index;
}

int main()
{
    long long x = 0, y = 0;

    const int res = scanf("%lld %lld", &x, &y);
    assert(res == 2);
    long long response[1000];
    const long long index = calc(x, y, response);

    for (long long i = 0; i <= index; ++i)
    {
        printf("%lld ", response[i]);
    }

    return 0;
}
