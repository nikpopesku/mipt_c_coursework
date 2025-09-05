#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int long long size;
    unsigned char* sieve;
} sieve_t;

sieve_t init_sieve(const int long long n)
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

int long long solve(const int long long n)
{
    sieve_t s = init_sieve(n + 1);
    assert(s.sieve != NULL && s.size > 0);

    for (int long long i = 2; i <= n + 1; ++i)
    {
        if (s.sieve[i] == 1) continue;

        int long long index = i * i;
        while (index <= n + 1)
        {
            if (s.sieve[index] == 0)
            {
                s.sieve[index] = 1;
            }

            index += i;
        }
    }


    int long long response = 0;

    for (int long long i = 2; i < n + 1; ++i)
    {
        if (s.sieve[i] == 0)
        {
            ++response;
        }
    }

    free_sieve(&s);

    return response;
}


int main()
{
    int long long n = 0;

    const int res = scanf("%lld", &n);
    assert(res == 1);

    const int long long number = solve(n);

    printf("%u", number);

    return 0;
}
