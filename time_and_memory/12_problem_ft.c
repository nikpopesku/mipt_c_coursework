#include <assert.h>
#include <stdio.h>

unsigned long long gcd(unsigned long long a, unsigned long long b) {
    if (a == b) {
        return a;
    }

    if (a > b) {
        return gcd(a - b, b);
    }

    return gcd(b, a);
}

int solve(unsigned long long P) {
    if (P % 2 == 0 || P % 3 == 0 || P % 5 == 0) {
        return 0;
    }
    for (unsigned long long i = 7; i * i < P; ++i) {
        if (gcd(P, i) != 1) {
            return 0;
        }
    }

    return 1;
}

int main() {
    unsigned long long P = 0;

    const int res = scanf("%llu", &P);
    assert(res == 1);

    const int answer = solve(P);

    printf("%d", answer);

    return 0;
}