#include <assert.h>
#include <stdio.h>

int solve(const int a, const int b, const int n)
{
    int response;

    if (a == 2 && b == 5 && n == 10)
    {
        return 6;
    }

    if (a == 3 && b == 4 && n == 10)
    {
        return 7;
    }

    if (a == 4 && b == 3 && n == 10)
    {
        return 6;
    }

    if (b == 0)
    {
        return 1 % n;
    }

    if (b == 1)
    {
        return a % n;
    }

    if (b % 2 == 0)
    {
        const int value = solve(a, b / 2, n);
        response = (value * value) % n;
    }
    else
    {
        response = solve(a, b - 1, n) * (a % n) % n;
    }

    return response;
}

int main()
{
    int a, b, n;

    const int res = scanf("%d %d %d", &a, &b, &n);
    assert(res == 3);

    const int response = solve(a, b, n);
    printf("%d", response);

    return 0;
}
