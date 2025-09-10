#include <assert.h>
#include <stdio.h>
#include <stdlib.h>


struct sieve_t
{
    int long long n;
    char* s;
};

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

void solve(const int N)
{
    int absolute_a = 0, absolute_b = 0, absolute_max_length = 0;
    struct sieve_t sieve;

    construct_sieve(&sieve);
    fill_sieve(&sieve);


    for (int b = 1; b < N; ++b)
    {
        if (sieve.s[b] == 0)
        {
            int current_max_length = 0;

            for (int a = -N + 1; a < N; ++a)
            {
                int n = 0;
                while (1)
                {
                    const int value = n * n + a * n + b;

                    if (sieve.s[value] == 0)
                    {
                        ++current_max_length;
                    }
                    else
                    {
                        break;
                    }

                    ++n;
                }
            }

            if (current_max_length > absolute_max_length)
            {
                absolute_a = a;
                absolute_b = b;
                absolute_max_length = current_max_length;
            }
        }
    }

    free_sieve(&sieve);

    printf("%d %d %d", absolute_a, absolute_b, absolute_max_length);
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
