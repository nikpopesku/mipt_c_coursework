#include <assert.h>
#include <stdio.h>

unsigned long long gcd(unsigned long long x, unsigned long long y) {
    if (y > x)
        return gcd(y, x);
    assert (y > 0);
    const unsigned long long q = x % y;
    if (q == 0)
        return y;
    return gcd(y, q);
}

int main() {
    unsigned long long x = 0, y = 0, g;

    const int res = scanf("%llu %llu", &x, &y);
    assert(res == 2);
    g = gcd(x, y);
    printf("%llu\n", g);
    return 0;
}