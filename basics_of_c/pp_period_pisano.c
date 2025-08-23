#include <assert.h>
#include <stdio.h>

void solve(const int x, const int m)
{
    int first_value = 0 % m;
    int second_value = 1 % m;
    int fib_response = 0;
    int value = 0;
    int counter = 2;

    do
    {
        value = (first_value + second_value) % m;
        first_value = second_value;
        second_value = value;
        if (++counter == x)
        {
            fib_response = value;
        }
    }
    while (!(second_value == 1 && first_value == 0) || counter < x);

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
