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

int nth_prime(const struct sieve_t sv, const int N)
{
    int counter = 0;
    for (int long long i = 2; i < sv.n; ++i)
    {
        if (sv.s[i] == 0) ++counter;

        if (counter == N)
        {
            return i;
        }
    }

    return -1;
}

void free_sieve(struct sieve_t* sv)
{
    free(sv->s);
    sv->s = 0;
    sv->n = 0;
}


int main()
{
    int long long N = 0;

    const int res = scanf("%lld", &N);
    assert(res == 1);

    struct sieve_t sieve;
    construct_sieve(&sieve);
    fill_sieve(&sieve);
    nth_prime(sieve, 10);

    free_sieve(&sieve);

    return 0;
}
