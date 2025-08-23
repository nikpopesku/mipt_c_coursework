#include <assert.h>
#include <stdio.h>

void solve(const int x, const int m)
{
    int last = 0 % m;
    int penultimate = 1 % m;
    int value = 0;
    int fib_response = 0;
    int counter = 2;
    int i = 2;

    while (i <= x)
    {
        value = (last + penultimate) % m;
        last = penultimate;
        penultimate = value;
        if (i == x)
        {
            fib_response = value;
        }
        ++i;
    }

    printf("%d %d", fib_response, counter - 2);
}

int main()
{
    int x = 0, m = 0;

    const int res = scanf("%d %d", &x, &m);
    assert(res == 2);

    solve(x, m);

    return 0;
}
