#include <assert.h>
#include <stdio.h>

void solve(int long long x)
{
    int long long f[10000];
    int coef[10000];
    f[0] = 1;
    f[1] = 1;
    int counter = 1;
    int max_counter;
    coef[0] = 0;
    coef[1] = 0;

    while (f[counter] < x)
    {
        ++counter;
        f[counter] = f[counter - 1] + f[counter - 2];
        coef[counter] = 0;
    }

    if (f[counter] > x)
    {
        --counter;
    }

    max_counter = counter;

    while (x > 0)
    {
        if (f[counter] <= x)
        {
            x -= f[counter];
            coef[counter] = 1;
            counter -= 2;
        }
        else
        {
            --counter;
        }
    }

    for (int i = max_counter; i >= 1; --i)
    {
        printf("%d", coef[i]);
    }
}

int main()
{
    int long long x = 0;

    const int res = scanf("%lld", &x);
    assert(res == 1);

    solve(x);

    return 0;
}
