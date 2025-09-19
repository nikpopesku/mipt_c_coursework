#include "u_template.h"
// #include <assert.h>


void fill_sieve(const struct sieve_t *sv) {
    sv->mod1[0] = 1;

    for (int i = 0; i < sv->n * 8; ++i) {
        if ((sv->mod1[i / 8] & 1 << (i % 8)) == 0) {
            const int val0 = 6 * i + 1;
            for (int index = val0 + val0; index < sv->n * 8 * 6 + 1; index += val0) {
                if ((index - 1) % 6 == 0 && (index % 2 == 0 || index % 3 == 0 || index % 5 == 0 || index % val0 == 0)) {
                    const int val = (index - 1) / 6;
                    sv->mod1[val / 8] = sv->mod1[val / 8] | 1 << (val % 8);
                }
                if ((index - 5) % 6 == 0) {
                    const int val = (index - 5) / 6;
                    sv->mod5[val / 8] = sv->mod5[val / 8] | 1 << (val % 8);
                }
            }
        }
        if ((sv->mod5[i / 8] & 1 << (i % 8)) == 0) {
            const int val0 = 6 * i + 5;
            for (int index = val0 + val0; index <= sv->n * 8 * 6 + 5; index += val0) {
                if ((index - 5) % 6 == 0 && (index % 2 == 0 || index % 3 == 0 || index % 5 == 0 || index % val0 == 0)) {
                    const int val = (index - 5) / 6;
                    sv->mod5[val / 8] = sv->mod5[val / 8] | 1 << (val % 8);
                }
                if ((index - 1) % 6 == 0) {
                    const int val = (index - 1) / 6;
                    sv->mod1[val / 8] = sv->mod1[val / 8] | 1 << (val % 8);
                }
            }
        }
    }

    // assert(sv->mod1[0] == 17);
    // assert(sv->mod5[0] == 32);
}

int is_prime(const struct sieve_t *sv, const unsigned n) {
    if (n >= 1 && (n - 1) % 6 == 0) {
        const int val = (n - 1) / 6;

        return (sv->mod1[val / 8] & 1 << (val % 8)) == 0 ? 1 : 0;
    }

    if (n >= 5 && (n - 5) % 6 == 0) {
        const int val = (n - 5) / 6;

        return (sv->mod1[val / 8] & 1 << (val % 8)) == 0 ? 1 : 0;
    }

    return 0;
}
