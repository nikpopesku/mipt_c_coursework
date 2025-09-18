#include "u_template.h"


void fill_sieve(const struct sieve_t* sv)
{
    sv->s[0] = sv->s[0] | 3;

    for (int long long i = 2; i * i < sv->n * 8; ++i)
    {
        if ((sv->s[i / 8] & 1 << (i % 8)) == 0)
        {
            for (int long long index = i * i; index < sv->n * 8; index += i)
            {
                sv->s[index / 8] = sv->s[index / 8] | 1 << (index % 8);
            }
        }
    }

    assert(sv->s[0] == 83);
    assert(sv->s[1] == 215);
}

int is_prime(const struct sieve_t* sv, const unsigned n)
{
    return (sv->s[n / 8] & 1 << (n % 8)) == 0;
}
