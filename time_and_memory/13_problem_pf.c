#include <assert.h>
#include <stdio.h>

unsigned long long gcd(unsigned long long a, unsigned long long b) {
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

        for (unsigned long long i = 7; i < a2; ++i) {
            if (gcd(a2, i) != 1) {
                continue;
            }
        }
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
