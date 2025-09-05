#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    unsigned size;
    unsigned char* sieve;
} sieve_t;

sieve_t init_sieve(const unsigned int n)
{
    unsigned char* a = calloc(n, sizeof(unsigned char));
    sieve_t sieve;
    sieve.size = n;
    sieve.sieve = a;

    return sieve;
}

void free_sieve(sieve_t* s)
{
    free(s->sieve);
    s->sieve = 0;
    s->size = 0;
}

unsigned int solve(const unsigned int n)
{
    sieve_t s = init_sieve(n + 1);
    assert(s.sieve != NULL && s.size > 0);

    for (unsigned int i = 2; i < n + 1; ++i)
    {
        unsigned int index = i * i;
        while (index < n + 1)
        {
            if (s.sieve[index] == 0)
            {
                s.sieve[index] = 1;
            }

            index += i;
        }
    }


    unsigned int response = 0;

    for (unsigned int i = 2; i < n + 1; ++i)
    {
        if (s.sieve[i] == 0)
        {
            ++response;
        }
    }

    free_sieve(&s);

    return response;
}


unsigned is_prime(const sieve_t s, unsigned n)
{
    assert(n < s.size);
    return s.sieve[n] == 1 ? 0 : 1;
}

int main()
{
    unsigned int n = 0;

    const int res = scanf("%lld", &n);
    assert(res == 1);

    const unsigned int  number = solve(n);

    printf("%u", number);

    return 0;
}
