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

int is_circular_prime(const struct sieve_t sieve, const int prime)
{
    int degree = 10;

    while (prime / degree > 0)
    {
        degree *= 10;
    }

    degree /= 10;
    int number;

    do
    {
        number = prime % 10 * degree + prime / 10;

        if (sieve.s[number] == 1)
        {
            return 0;
        }
    }
    while (number != prime);

    return 1;
}

int solve(const struct sieve_t sieve, const int N)
{
    int up = N, down = N, counter = 0;

    while (up < 10000000 || down > 0)
    {
        ++counter;
        if (up < 10000000)
        {
            ++up;

            if (sieve.s[up] == 0 && is_circular_prime(sieve, up))
            {
                break;
            }
        }

        if (down > 0)
        {
            --down;

            if (sieve.s[down] == 0 && is_circular_prime(sieve, down))
            {
                break;
            }
        }
    }

    return counter;
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

    const int response = solve(sieve, N);

    printf("%d", response);

    free_sieve(&sieve);

    return 0;
}
