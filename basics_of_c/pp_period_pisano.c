#include <assert.h>
#include <stdio.h>

void solve(const int x, const int m)
{
    int first_value = 0 % m;
    int second_value = 1 % m;
    int pisano_response = 0;
    int fib_response = 0;
    int value = 0;

    do
    {
        value = (first_value + second_value) % m;
        first_value = second_value;
        second_value = value;
        ++pisano_response;
    }
    while (!(second_value == 1 && first_value == 0));

    printf("%d %d", fib_response, pisano_response);
}

int main()
{
    int x = 0, m = 0;

    const int res = scanf("%d %d", &x, &m);
    assert(res == 2);

    solve(x, m);

    return 0;
}
