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

void fill_sieve(const struct sieve_t* sieve)
{
    for (int i = 2; i < sieve->n; ++i)
    {
        if (sieve->s[i] == 0)
        {
            int index = i * i;

            while (index < sieve->n)
            {
                sieve->s[index] = 1;
                index += i;
            }
        }
    }
}

void solve(int N)
{
}

void free_sieve(struct sieve_t* sieve)
{
    free(sieve->s);
    sieve->s = 0;
    sieve->n = 0;
}

int main()
{
    int N = 0;
    struct sieve_t sieve;

    const int res = scanf("%d", &N);
    assert(res == 1);

    construct_sieve(&sieve);
    fill_sieve(&sieve);
    free_sieve(&sieve);

    solve(N);

    return 0;
}
