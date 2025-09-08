#include "u_template.h"
#include <stdio.h>
#include <assert.h>
#include <math.h>
#include <assert.h>
#include <stdlib.h>

void construct_sieve(sieve_t* sv, int N)
{
    int value = log2(N);
    int length = N * (value + log2(value));
    sv->n = length;
    char* a = calloc(length, sizeof(char));
    sv->s = a;
}

void fill_sieve(sieve_t* sv)
{
}


int nth_prime(sieve_t* sv, int N)
{
    return N + 4;
}

void free_sieve(sieve_t* s)
{
    free(s->s);
    s->s = 0;
    s->n = 0;
}

int main()
{
    int n = 0;

    const int res = scanf("%d", &n);
    assert(res == 1);

    sieve_t sieve;
    fill_sieve(&sieve);
    const int number = nth_prime(&sieve, n);

    printf("%d", number);

    free_sieve(&sieve);

    return 0;
}
