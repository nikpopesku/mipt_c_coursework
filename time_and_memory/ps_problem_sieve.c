#include "u_template.h"

void fill_sieve(struct sieve_t* sv)
{
    for (int long long i = 2; i <= sv->n; ++i)
    {
        if (sv->s[i] == 0)
        {
            int long long index = i * i;

            while (index <= sv->n)
            {
                sv->s[index] = 1;
                index += i;
            }
        }
    }
}


int long long nth_prime(struct sieve_t* sv, int long long N)
{
    int long long counter = 0;
    for (int long long i = 2; i <= sv->n; ++i)
    {
        if (sv->s[i] == 0) ++counter;

        if (counter == N)
        {
            return i;
        }
    }

    return -1;
}
