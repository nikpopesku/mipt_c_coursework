#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

#include "u_template.h"

void construct_sieve(static struct sieve_t* sv)
{
    sv->n = 1000000;
    unsigned char* a = calloc(sv->n, sizeof(unsigned char));
    sv->s = a;
}

void fill_sieve(struct sieve_t* sv);
int is_prime(struct sieve_t* sv, unsigned n);

void solve(int long long N)
{
}


int main()
{
    int long long N = 0;

    const int res = scanf("%lld", &N);
    assert(res == 1);

    struct sieve_t sieve;
    construct_sieve(sieve);
    solve(N);

    return 0;
}
