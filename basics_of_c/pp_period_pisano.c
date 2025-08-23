#include <assert.h>
#include <stdio.h>

void solve(const int x, const int m)
{
    int last = 0 % m;
    int penultimate = 1 % m;
    int value = 0;
    int fib_response = 0;
    int pisano_response = 0;
    int counter = 1;

    while (counter <= x || !(value == 1 && last == 0))
    {
        value = (last + penultimate) % m;
        last = penultimate;
        penultimate = value;
        if (++counter == x)
        {
            fib_response = value;
        }
        if (value == 1 && last == 0 && pisano_response == 0)
        {
            pisano_response = counter;
        }
    }

    printf("%d %d", fib_response, pisano_response - 1);
}

int main()
{
    int x = 0, m = 0;

    const int res = scanf("%d %d", &x, &m);
    assert(res == 2);

    solve(x, m);

    return 0;
}
