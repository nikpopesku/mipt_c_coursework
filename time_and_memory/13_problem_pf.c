#include <assert.h>
#include <stdio.h>

unsigned long long solve(int k, int n) {
    return 0;
}

int main() {
    int k, n;

    const int res = scanf("%d", &k, &n);
    assert(res == 2);

    const unsigned long long answer = solve(k, n);

    printf("%llu", answer);

    return 0;
}