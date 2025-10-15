#include <assert.h>
#include <stdio.h>

unsigned long long solve(const int k, const int n) {
    unsigned long long a0 = 0, a1 = 1;
    unsigned long long a2 = k;

    while (a2 >= a1) {
        const unsigned long long temp = a2;
        a2 = k * a1 + n * a0;
        a0 = a1;
        a1 = temp;


    }

    return 0;
}

int main() {
    int k, n;

    const int res = scanf("%d %d", &k, &n);
    assert(res == 2);

    const unsigned long long answer = solve(k, n);

    printf("%llu", answer);

    return 0;
}
