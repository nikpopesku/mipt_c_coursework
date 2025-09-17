#include "u_template.h"


void fill_sieve(const struct sieve_t* sv)
{
    sv->s[0] = sv->s[0] | 3;

    for (int long long i = 2; i * i < sv->n * 8; ++i)
    {
        if (sv->s[(i - 2) / 8] == 0)
        {
            for (int long long index = i * i; index < sv->n * 8; index += i)
            {
                sv->s[index] = 1;
                index += i;
            }
        }
    }
}
int is_prime(struct sieve_t* sv, unsigned n)
{

}
