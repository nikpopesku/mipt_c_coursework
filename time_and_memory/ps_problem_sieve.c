#include "u_template.h"
#include <stdio.h>
#include <assert.h>

void fill_sieve(sieve_t* sv)
{
}


int nth_prime(sieve_t* sv, int N)
{
    return N + 4;
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

    return 0;
}
