#include <assert.h>
#include <stdio.h>


int gcd(const int a, const int b)
{
    if (a == b) return a;

    if (b > a)
    {
        return gcd(b, a);
    }

    return gcd(a - b, b);
}

int long long solve(const int N)
{
    int long long response = 2;

    for (int i = 3; i <= N; ++i)
    {
        response = i * response / gcd(i, response);
    }

    return response;
}


int main()
{
    int N = 0;

    const int res = scanf("%d", &N);
    assert(res == 1);

    const int response = solve(N);

    printf("%d", response);

    return 0;
}
