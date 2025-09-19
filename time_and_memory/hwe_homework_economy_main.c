#include <stdlib.h>
#include <stdio.h>
#include <assert.h>

#include "hwe_homework_economy.c"

void construct_sieve(struct sieve_t* sieve)
{
    sieve->n = 1000;
    unsigned char* mod1 = calloc(sieve->n, sizeof(unsigned char));
    unsigned char* mod5 = calloc(sieve->n, sizeof(unsigned char));
    sieve->mod1 = mod1;
    sieve->mod5 = mod5;
}

int long long nth_prime(const struct sieve_t sv, int long long N)
{
    if (N == 1)
    {
        return 2;
    }

    if (N == 2)
    {
        return 3;
    }

    N -= 2;
    int counter = 0;

    for (int i = 0; i < sv.n * 8; ++i)
    {
        if ((sv.mod1[i / 8] & 1 << (i % 8)) == 0)
        {
            ++counter;
        }

        if (counter == N)
        {
            return 6 * i + 1;
        }

        if ((sv.mod5[i / 8] & 1 << (i % 8)) == 0)
        {
            ++counter;
        }

        if (counter == N)
        {
            return 6 * i + 5;
        }
    }

    return -1;
}

void free_sieve(struct sieve_t* sieve)
{
    free(sieve->mod1);
    free(sieve->mod5);
    sieve->n = 0;
    sieve->mod1 = 0;
    sieve->mod5 = 0;
}


int main()
{
    struct sieve_t sieve;
    int n;
    const int response = scanf("%d", &n);
    assert(response == 1);

    construct_sieve(&sieve);
    fill_sieve(&sieve);
    int answer = nth_prime(sieve, n);

    printf("%d", answer);

    free_sieve(&sieve);

    return 0;
}
