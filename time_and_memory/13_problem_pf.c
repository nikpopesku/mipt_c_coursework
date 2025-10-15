#include <assert.h>
#include <math.h>
#include <stdio.h>

unsigned long long gcd(const unsigned long long a, const unsigned long long b) {
    if (a == b) {
        return a;
    }

    if (a > b) {
        if (a % b == 0) {
            return b;
        }

        return gcd(a % b, b);
    }

    return gcd(b, a);
}

unsigned long long calc_power(const unsigned long long a, const unsigned long long power, const unsigned long long p) {
    if (power == 0) {
        return a;
    }

    if (power % 2 == 1) {
        return (a % p) * calc_power(a, power - 1, p) % p;
    }

    return calc_power(((a % p) * (a % p)) % p, power / 2, p);
}

int has_divisor(const unsigned long long number) {
    for (unsigned long long i = 7; i < number; ++i) {
        if (gcd(number, i) != 1) {
            return 1;
        }

        // if (number == 37 && i == 7) {
        //     int xxx = 5;
        // }
        if (calc_power(i, number, number) != 1) {
            return 1;
        }
    }

    return 0;
}

unsigned long long solve(const int k, const int n) {
    unsigned long long a0 = 0, a1 = 1;
    unsigned long long a2 = k;
    unsigned long long max_prime = 0;

    while (a2 >= a1) {
        const unsigned long long temp = a2;
        a2 = k * a1 + n * a0;
        a0 = a1;
        a1 = temp;

        if (a2 < temp) {
            break;
        }

        if (a2 == 2 && max_prime == 0) {
            max_prime = 2;

            continue;
        }

        if (a2 == 3 && max_prime == 0) {
            max_prime = 3;

            continue;
        }

        if (a2 == 5 && max_prime == 0) {
            max_prime = 5;

            continue;
        }

        if (a2 % 2 == 0 || a2 % 3 == 0 || a2 % 5 == 0) {
            continue;
        }

        if (has_divisor(a2) == 1) {
            continue;
        }

        max_prime = a2;
    }

    return max_prime;
}

int main() {
    int k, n;

    const int res = scanf("%d %d", &k, &n);
    assert(res == 2);

    const unsigned long long answer = solve(k, n);

    printf("%llu", answer);

    return 0;
}
