#include <assert.h>
#include <stdio.h>

unsigned long long MAX = 1ULL << 60;

unsigned long long gcd(const unsigned long long a, const unsigned long long b)
{
    if (a == b)
    {
        return a;
    }

    if (a > b)
    {
        if (a % b == 0)
        {
            return b;
        }

        return gcd(a % b, b);
    }

    return gcd(b, a);
}

// Modular multiplication to avoid overflow
unsigned long long mul_mod(unsigned long long a, unsigned long long b, const unsigned long long mod)
{
    unsigned long long result = 0;
    a %= mod;
    while (b > 0)
    {
        if (b & 1)
        {
            result = (result + a) % mod;
        }
        a = (a * 2) % mod;
        b >>= 1;
    }
    return result;
}

// Modular exponentiation
unsigned long long pow_mod(unsigned long long base, unsigned long long exp, const unsigned long long mod)
{
    unsigned long long result = 1;
    base %= mod;
    while (exp > 0)
    {
        if (exp & 1)
        {
            result = mul_mod(result, base, mod);
        }
        base = mul_mod(base, base, mod);
        exp >>= 1;
    }
    return result;
}

// Miller-Rabin primality test
int miller_rabin_test(const unsigned long long n, const unsigned long long a)
{
    unsigned long long d;
    int r;
    unsigned long long x;
    if (n <= 1) return 0;
    if (n == 2) return 1;
    if (n % 2 == 0) return 0;

    d = n - 1;
    r = 0;
    while (d % 2 == 0)
    {
        d >>= 1;
        r++;
    }

    x = pow_mod(a, d, n);

    if (x == 1 || x == n - 1)
    {
        return 1;
    }

    for (int i = 0; i < r - 1; i++)
    {
        x = mul_mod(x, x, n);
        if (x == n - 1)
        {
            return 1;
        }
    }

    return 0;
}

int is_prime(unsigned long long n)
{
    if (n <= 1) return 0;
    if (n == 2 || n == 3) return 1;
    if (n % 2 == 0) return 0;
    if (n % 3 == 0) return 0;
    if (n < 9) return 1;


    for (int i = 0; i < 12; i++)
    {
        const unsigned long long witnesses[] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37};
        if (n == witnesses[i]) return 1;
        if (n < witnesses[i]) break;
        if (!miller_rabin_test(n, witnesses[i]))
        {
            return 0;
        }
    }

    return 1;
}

unsigned long long solve(const int k, const int n)
{
    unsigned long long a0 = 0, a1 = 1;
    unsigned long long max_prime = 0;

    while (1)
    {
        const unsigned long long a2 = k * a1 + n * a0;

        if (a2 >= MAX)
        {
            break;
        }

        if (is_prime(a2))
        {
            max_prime = a2;
        }

        a0 = a1;
        a1 = a2;
    }

    return max_prime;
}

int main()
{
    int k, n;
    unsigned long long answer;

    const int res = scanf("%d %d", &k, &n);
    assert(res == 2);

    answer = solve(k, n);

    printf("%llu", answer);

    return 0;
}
