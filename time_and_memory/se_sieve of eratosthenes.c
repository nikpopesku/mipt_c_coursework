#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    unsigned size;
    unsigned char* sieve;
} sieve_t;

int long long solve(const unsigned int n)
{
    sieve_t s = init_sieve(100);
    assert(s.sieve != NULL && s.size > 0);
}

sieve_t init_sieve(const unsigned int n)
{
    unsigned char* a = calloc(n, sizeof(unsigned char));
    sieve_t sieve;
    sieve.size = n;
    sieve.sieve = a;

    return sieve;
}

void free_sieve(sieve_t* s)
{
    free(s->sieve);
    s->sieve = 0;
    s->size = 0;
}

unsigned is_prime(const sieve_t s, unsigned n)
{
    assert(n < s.size);
    return s.sieve[n] == 1 ? 0 : 1;
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
