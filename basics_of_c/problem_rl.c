#include <assert.h>
#include <stdio.h>

unsigned long long gcd(unsigned long long x, unsigned long long y) {
    while (y != x)
    {
        if (y > x)
        {
            y -= x;
        } else
        {
            x -= y;
        }
    }

    return y;
}

int main() {
    unsigned long long x = 0, y = 0, g;

    const int res = scanf("%llu %llu", &x, &y);
    assert(res == 2);
    g = gcd(x, y);
    printf("%llu\n", g);
    return 0;
}