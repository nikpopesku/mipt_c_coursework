#include <assert.h>
#include <stdio.h>

void solve(const int x, const int m)
{
    int first_value = 0 % m;
    int second_value = 1 % m;
    int pisano_response = 0;
    int fib_response = 0;

    do
    {
        const int value = (first_value + second_value) % m;
        second_value = value;
        first_value = second_value;
        ++pisano_response;
    }
    while (!(first_value == 0 && second_value == 1));

    printf("%d %d", fib_response, pisano_response);
}

int main()
{
    unsigned int x, m;

    const int res = scanf("%u %u", &x, &m);
    assert(res == 2);

    solve(x, m);

    return 0;
}
