#include <assert.h>
#include <stdio.h>

void solve(const int x, const int m)
{
    int last = 0 % m;
    int penultimate = 1 % m;
    int value = 0;
    int fib_response = 0;
    int pisano_period = 0;
    int counter = 1;

    while (!(value == 1 && last == 0))
    {
        value = (last + penultimate) % m;
        last = penultimate;
        penultimate = value;
        if (value == 1 && last == 0 && pisano_period == 0)
        {
            pisano_period = counter;
        }
    }

    --pisano_period;

    // for (int i= x / pisano_period; i < )

    printf("%d %d", fib_response, pisano_period);
}

int main()
{
    int x = 0, m = 0;

    const int res = scanf("%d %d", &x, &m);
    assert(res == 2);

    solve(x, m);

    return 0;
}
