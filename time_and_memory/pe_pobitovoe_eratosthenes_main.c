#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include "pe_pobitovoe_eratosthenes.c"

void construct_sieve(static struct sieve_t* sv)
{
    sv->n = 1000000;
    unsigned char* a = calloc(sv->n, sizeof(unsigned char));
    sv->s = a;
}


int main()
{
    int long long N = 0;

    const int res = scanf("%lld", &N);
    assert(res == 1);

    struct sieve_t sieve;
    construct_sieve(&sieve);
    fill_sieve(&sieve);

    return 0;
}
