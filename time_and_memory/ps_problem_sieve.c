#include "u_template.h"

void fill_sieve(struct sieve_t* sv)
{
    for (int i = 2; i < sv->n; ++i)
    {
        if (sv->s[i] == 0)
        {
            int index = i * i;

            while (index < sv->n)
            {
                sv->s[index] = 1;
                index += i;
            }
        }
    }
}


int nth_prime(struct sieve_t* sv, int N)
{
    int counter = 0;
    for (int i = 2; i < sv->n; ++i)
    {
        if (sv->s[i] == 0) ++counter;

        if (counter == N)
        {
            return i;
        }
    }

    return -1;
}
