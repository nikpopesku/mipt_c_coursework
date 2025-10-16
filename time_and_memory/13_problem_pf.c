#include <assert.h>
#include <stdio.h>

// Miller-Rabin primality test
unsigned long long mod_mul(unsigned long long a, unsigned long long b, const unsigned long long mod) {
    unsigned long long result = 0;
    a %= mod;
    while (b > 0) {
        if (b % 2 == 1) {
            result = (result + a) % mod;
        }
        a = (a * 2) % mod;
        b /= 2;
    }
    return result % mod;
}

unsigned long long mod_pow(unsigned long long base, unsigned long long exp, const unsigned long long mod) {
    unsigned long long result = 1;
    base %= mod;
    while (exp > 0) {
        if (exp % 2 == 1) {
            result = mod_mul(result, base, mod);
        }
        base = mod_mul(base, base, mod);
        exp /= 2;
    }
    return result;
}

int miller_rabin(const unsigned long long n, const unsigned long long a) {
    unsigned long long d;
    unsigned long long x;
    int r;
    if (n <= 1) return 0;
    if (n == 2) return 1;
    if (n % 2 == 0) return 0;
    

    d = n - 1;
    r = 0;
    while (d % 2 == 0) {
        d /= 2;
        r++;
    }
    
    x = mod_pow(a, d, n);
    
    if (x == 1 || x == n - 1) {
        return 1;
    }
    
    for (int i = 0; i < r - 1; i++) {
        x = mod_mul(x, x, n);
        if (x == n - 1) {
            return 1;
        }
    }
    
    return 0;
}

int is_prime(unsigned long long n) {
    unsigned long long witnesses[9] = {2, 3, 5, 7, 11, 13, 17, 19, 23};
    if (n <= 1) return 0;
    if (n <= 3) return 1;
    if (n % 2 == 0 || n % 3 == 0) return 0;
    if (n % 5 == 0) return 0;
    
    // Test with multiple bases for certainty
    for (int i = 0; i < 9; i++) {
        if (n == witnesses[i]) return 1;
        if (!miller_rabin(n, witnesses[i])) {
            return 0;
        }
    }
    
    return 1;
}

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

unsigned long long calc_power(const unsigned long long a, const unsigned long long power, const unsigned long long p)
{
    if (power == 0)
    {
        return 1;
    }

    if (power % 2 == 1)
    {
        return ((a % p) * calc_power(a, power - 1, p) % p) % p;
    }

    return calc_power(((a % p) * (a % p)) % p, power / 2, p);
}

int has_divisor(const unsigned long long number)
{
    for (unsigned long long i = 7; i * i < number; i += 2)
    {
        if (gcd(number, i) != 1)
        {
            return 1;
        }

        if (calc_power(i, number - 1, number) != 1)
        {
            return 1;
        }
    }

    return 0;
}

unsigned long long solve(const int k, const int n) {
    unsigned long long a0 = 0, a1 = 1;
    unsigned long long a2 = k;
    unsigned long long max_prime = 0;

    while (a2 < MAX) {
        const unsigned long long temp = a2;
        a2 = k * a1 + n * a0;
        a0 = a1;
        a1 = temp;

        if (a2 >= MAX) {
            break;
        }

        if (is_prime(a2)) {
            max_prime = a2;
        }
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
