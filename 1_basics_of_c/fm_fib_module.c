#include <assert.h>
#include <stdio.h>

int solve(const int x, const int m)
{
    if (x == 0)
    {
        return 0;
    }

    if (x == 1)
    {
        return 1 % m;
    }

    int last = 0;
    int penultimate = 1 % m;
    int current = 0;

    for (int i = 2; i <= x; ++i)
    {
        current = (last + penultimate) % m;
        last = penultimate;
        penultimate = current;
    }

    return current;
}

int main()
{
    unsigned int x, m;

    const int res = scanf("%u %u", &x, &m);
    assert(res == 2);

    const int response = solve(x, m);
    printf("%d", response);

    return 0;
}
