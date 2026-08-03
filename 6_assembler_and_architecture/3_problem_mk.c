#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

enum Register {
    A = 0,
    B = 1,
    C = 2,
    D = 3
};

int main() {
    unsigned val, counter = 0;
    unsigned regs[4];
    size_t cap = 16, len = 0;
    unsigned *buf = calloc(cap, sizeof(unsigned)), *new_buf;
    enum Register first;
    enum Register second;

    while (scanf("%x", &val) == 1 && val != 240) {
        if (len + 1 >= cap) {
            cap *= 2;
            new_buf = realloc(buf, cap);
            buf = new_buf;
            assert(buf != NULL);
        }
        buf[len++] = val;
    }

    for (counter = 0; counter < len; ++counter) {
        val = buf[counter];
        if (val >> 7 == 0) {
            regs[3] = val;
            continue;
        }

        first = (val & (3 << 2)) >> 2;
        second = val & 3;

        switch (val >> 4) {
            case 8:
                regs[first] = (regs[first] + regs[second]) % 256;
                break;
            case 9:
                regs[first] = (regs[first] - regs[second]) % 256;
                break;
            case 10:
                regs[first] = (regs[first] * regs[second]) % 256;
                break;
            case 11:
                regs[first] = (regs[first] / regs[second]) % 256;
                break;
            case 12:
                if ((val & (1 << 2)) >> 2 == 1) {
                    printf("%d\n", regs[second]);
                } else {
                    scanf("%u", &regs[second]);
                }
                break;
            default:
                printf("ERROR\n");
                free(buf);
                return 0;
        }
    }

    free(buf);

    return 0;
}
