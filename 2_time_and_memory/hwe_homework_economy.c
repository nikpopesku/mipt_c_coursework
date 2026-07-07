#include "u_template.h"
#include <assert.h>


void fill_sieve(const struct sieve_t* sv)
{
    const long long limit = sv->n * 8;

    sv->mod1[0] = 1;

    for (int i = 0; 6 * i * i < limit; ++i)
    {
        if ((sv->mod1[i / 8] & 1 << (i % 8)) == 0)
        {
            const int long long p1 = 6 * i + 1;

            // Mark multiples of p1 that are of the form 6j+1.
            // These result from p1 * (6k+1), starting with k=i.
            // The starting index in the bit array is k' = 6*i*i + 2*i.
            for (long long k = 6 * i * i + 2 * i; k < limit; k += p1)
            {
                sv->mod1[k / 8] |= (1 << (k % 8));
            }

            // Mark multiples of p1 that are of the form 6j+5.
            // These result from p1 * (6k+5), starting with k=i.
            // The starting index is k' = 6*i*i + 6*i.
            for (long long k = 6 * i * i + 6 * i; k < limit; k += p1)
            {
                sv->mod5[k / 8] |= (1 << (k % 8));
            }
        }
        if ((sv->mod5[i / 8] & 1 << (i % 8)) == 0)
        {
            const int long long p5 = 6 * i + 5;

            // Mark multiples of p5 that are of the form 6j+1.
            // These result from p5 * (6k+5), starting with k=i.
            // The starting index is k' = 6*i*i + 10*i + 4.
            for (long long k = 6 * i * i + 10 * i + 4; k < limit; k += p5)
                sv->mod1[k / 8] |= (1 << (k % 8));

            // Mark multiples of p5 that are of the form 6j+5.
            // These result from p5 * (6k+1), starting with k=i+1.
            // The starting index is k' = 6*i*i + 12*i + 5.
            for (long long k = 6 * i * i + 12 * i + 5; k < limit; k += p5)
                sv->mod5[k / 8] |= (1 << (k % 8));
        }
    }

    assert(sv->mod1[0] == 17);
    assert(sv->mod5[0] == 32);
}

int is_prime(const struct sieve_t* sv, const unsigned n)
{
    if (n == 0)
    {
        return 0;
    }
    if (n == 2 || n == 3)
    {
        return 1;
    }

    if (n >= 1 && (n - 1) % 6 == 0)
    {
        const int val = (n - 1) / 6;

        return (sv->mod1[val / 8] & 1 << (val % 8)) == 0 ? 1 : 0;
    }

    if (n >= 5 && (n - 5) % 6 == 0)
    {
        const int val = (n - 5) / 6;

        return (sv->mod5[val / 8] & 1 << (val % 8)) == 0 ? 1 : 0;
    }

    return 0;
}
