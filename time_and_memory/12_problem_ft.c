#include <assert.h>
#include <stdio.h>

int gcd(unsigned long long a, unsigned long long b) {
    if (a == b) {
        return a;
    }

    if (a > b) {
        return gcd(a - b, b)
    }

    return gcd(b, a);
}

int solve(unsigned long long P) {
    return 4;
}

int main() {
    unsigned long long P = 0;

    const int res = scanf("%llu", &P);
    assert(res == 1);

    const int answer = solve(P);

    printf("%d", answer);

    return 0;
}