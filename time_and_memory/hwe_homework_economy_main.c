#include <stdlib.h>
#include <stdio.h>
#include <assert.h>

#include "hwe_homework_economy.c"

void construct_sieve(struct sieve_t* sieve)
{
    sieve->n = 1000000;
    unsigned char* a = calloc(sieve->n, sizeof(unsigned char));
    sieve->mod1 = a;
    sieve->mod5 = a;
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

    free_sieve(&sieve);

    return 0;
}