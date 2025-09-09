#include "u_template.h"
#include <stdio.h>
#include <assert.h>
#include <math.h>
#include <assert.h>
#include <stdlib.h>
#include "ps_problem_sieve.c"

void construct_sieve(struct sieve_t* sv, const int N)
{
    const int value = log2(N);
    sv->n = N * (value + log2(value));
    char* a = calloc(sv->n, sizeof(char));
    sv->s = a;
}


void free_sieve(struct sieve_t* s)
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

    struct sieve_t sieve;
    construct_sieve(&sieve, n);
    fill_sieve(&sieve);
    const int number = nth_prime(&sieve, n);

    printf("%d", number);

    free_sieve(&sieve);

    return 0;
}
