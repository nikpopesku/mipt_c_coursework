#include "u_template.h"


void fill_sieve(const struct sieve_t* sv)
{
    sv->mod1[0] = 1;

    for (int i = 0; i < sv->n * 8; ++i)
    {
        if ((sv->mod1[i / 8] & 1 << i % 8) == 0)
        {
            for (int index1 = 6 * i + 1, index5 = 6 * i + 5; index1 < sv->n * 8 * 6 && index5 < sv->n * 8 * 6; index1 +=
                 6, index5 += 6)
            {
                if (index1 % 2 == 0 || index1 % 3 == 0 || index1 % 4 == 0 || index1 % 5 == 0)
                {
                    sv->mod1[index1 / 8] = sv->mod1[index1 / 8] | 1 << index1 % 8;
                }
                if (index5 % 2 == 0 || index5 % 3 == 0 || index5 % 4 == 0 || index5 % 5 == 0)
                {
                    sv->mod5[index5 / 8] = sv->mod5[index5 / 8] | 1 << index5 % 8;
                }
            }
        }
    }
}

int is_prime(struct sieve_t* sv, unsigned n);
