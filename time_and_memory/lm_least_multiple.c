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
    sieve->n = 10000000;
    char* a = calloc(sieve->n, sizeof(char));
    sieve->s = a;
}

void fill_sieve(const struct sieve_t* sieve)
{
    for (int i = 0; i * i < sieve->n; ++i)
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

int long long solve(const int N)
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

    const int res = scanf("%d", &N);
    assert(res == 1);
    struct sieve_t sieve;
    construct_sieve(&sieve);
    fill_sieve(&sieve);

    const int response = solve(N);

    free_sieve(&sieve);

    printf("%d", response);

    free_sieve(&sieve);

    return 0;
}
