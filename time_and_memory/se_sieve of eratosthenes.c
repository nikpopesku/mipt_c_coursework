#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

struct sieve_t {
    unsigned size;
    unsigned char *sieve;
};

int long long solve(const int long long n)
{
    struct sieve_t s = init_sieve(100);
    assert(s.sieve != NULL && s.size > 0);
}

sieve_t init_sieve(const int long long n)
{

}

void free_sieve(struct sieve_t *s) {
    free(s->sieve);
    s->sieve = 0;
    s->size = 0;
}

unsigned is_prime(struct sieve_t s, unsigned n) {
    assert(n < s.size);
    return (s.sieve[n] == 1) ? 0 : 1;
}

int main()
{
    int long long n = 0;

    const int res = scanf("%lld", &n);
    assert(res == 1);

    const int long long number = solve(n);

    printf("%lld", number);

    return 0;
}
