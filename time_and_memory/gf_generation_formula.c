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

void fill_sieve(const struct sieve_t* sieve)
{
    for (int i = 2; i < sieve->n; ++i)
    {
        if (sieve->s[i] == 0)
        {
            int long long index = sieve->s[i] * sieve->s[i];

            while (index < sieve->n)
            {
                sieve->s[index] = 1;

                index += i;
            }
        }
    }
}

void free_sieve(struct sieve_t* sieve)
{
    free(sieve->s);
    sieve->s = 0;
    sieve->n = 0;
}

void solve(int N)
{
    struct sieve_t sieve;
    construct_sieve(&sieve);
    fill_sieve(&sieve);

    free_sieve(&sieve);
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
