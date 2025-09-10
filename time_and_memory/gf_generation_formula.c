#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

struct sieve_t
{
    int long long n;
    char* s;
};

int a, b, max_sequence_length;

void construct_sieve(struct sieve_t* sieve)
{
    sieve->n = 10000;
    char* a = calloc(sieve->n, sizeof(char));
    sieve->s = a;
}

void solve(int N)
{
    struct sieve_t sieve;
    construct_sieve(sieve);
}

int main()
{
    int N = 0;

    const int res = scanf("%d", &N);
    assert(res == 1);

    solve(N);

    printf("%d %d %d", a, b, max_sequence_length);

    return 0;
}
