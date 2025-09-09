#include "u_template.h"
#include <stdio.h>
#include <assert.h>
#include <math.h>
#include <assert.h>
#include <stdlib.h>

void construct_sieve(sieve_t* sv, const int N)
{
    const int value = log2(N);
    sv->n = N * (value + log2(value));
    char* a = calloc(sv->n, sizeof(char));
    sv->s = a;
}

void fill_sieve(const sieve_t* sv)
{
    for (int i = 2; i <= sv->n; ++i)
    {
        if (sv->s[i] == 0)
        {
            int index = i * i;

            while (index <= sv->n)
            {
                sv->s[index] = 1;
                index += i;
            }
        }
    }
}


int nth_prime(const sieve_t* sv, const int N)
{
    return sv->s[N];
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
    construct_sieve(&sieve, n);
    fill_sieve(&sieve);
    const int number = nth_prime(&sieve, n);

    printf("%d", number);

    free_sieve(&sieve);

    return 0;
}
