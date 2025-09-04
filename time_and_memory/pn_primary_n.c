#include <assert.h>
#include <stdio.h>

int is_prime(const int long long number)
{
    for (int i = 2; i * i <= number; ++i)
    {
        if (number % i == 0)
        {
            return 0;
        }
    }

    return 1;
}

int long long solve(const int long long N)
{
    int long long counter = 0, number = 2;

    while (counter < N)
    {
        if (is_prime(number))
        {
            ++counter;
        }
        ++number;
    }

    return number - 1;
}

int main()
{
    int long long N = 0;

    const int res = scanf("%lld", &N);
    assert(res == 1);

    const int long long number = solve(N);

    printf("%lld", number);

    return 0;
}
