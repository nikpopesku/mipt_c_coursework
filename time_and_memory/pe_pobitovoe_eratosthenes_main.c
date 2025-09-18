#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include "pe_pobitovoe_eratosthenes.c"

void construct_sieve(struct sieve_t* sv)
{
    sv->n = 1000000;
    unsigned char* a = calloc(sv->n, sizeof(unsigned char));
    sv->s = a;
}

int long long nth_prime(const struct sieve_t sv, const int N)
{
    int counter = 0;
    for (int long long i = 2; i < sv.n * 8; ++i)
    {
        if ((sv.s[i / 8] & 1 << (i % 8)) == 0)
        {
            ++counter;
        }

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
    const int long long response = nth_prime(sieve, 10);

    printf("%lld", response);

    free_sieve(&sieve);

    return 0;
}
