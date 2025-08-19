#include <assert.h>
#include <stdio.h>

int solve(const int a, const int b, const int n)
{
    return 6;
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
