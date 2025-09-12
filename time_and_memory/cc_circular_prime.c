#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

struct sieve_t
{
    int n;
    char* s;
};

void construct_sieve(struct sieve_t* sieve)
{
    char* a = calloc(10000000, sizeof(char));
    sieve->n = 10000000;
    sieve->s = a;
}

void solve(int N)
{
}

int main()
{
    int N = 0;
    struct sieve_t sieve;

    const int res = scanf("%d", &N);


    construct_sieve(&sieve);
    assert(res == 1);

    solve(N);

    return 0;
}
