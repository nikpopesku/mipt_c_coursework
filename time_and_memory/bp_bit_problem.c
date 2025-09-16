#include <assert.h>
#include <stdio.h>


void solve(int long long N)
{
    int msb = -1, lsb = -1, counter = 0;

    while (N > 0)
    {
        if (N & 1)
        {
            if (lsb == -1)
            {
                lsb = counter;
            }

            msb = counter;
        }

        N = N >> 1;
        ++counter;
    }

    if (msb == -1 && lsb == -1)
    {
        printf("NO\n");
    }
    else
    {
        printf("%d %d", msb, lsb);
    }
}


int main()
{
    int long long N = 0;

    const int res = scanf("%lld", &N);
    assert(res == 1);

    solve(N);

    return 0;
}
