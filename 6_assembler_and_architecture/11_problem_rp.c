#include <assert.h>
#include <fenv.h>
#include <stdio.h>
#include <string.h>

static unsigned as_uint(const float f) {
    unsigned u;
    memcpy(&u, &f, sizeof(unsigned));
    return u;
}

int main() {
    unsigned denominator;
    int numerator;
    unsigned frac = (1U << 23) - 1;
    float f_down, f_up;
    int res = scanf("%d", &numerator);
    assert(res == 1);
    res = scanf("%u", &denominator);
    assert(res == 1);

    fesetround(FE_DOWNWARD);
    f_down = (float) numerator / denominator;

    fesetround(FE_UPWARD);
    f_up = (float) numerator / denominator;

    if (f_down != f_up) {
        printf("0x%x 0x%x 0x%x 0x%x", (as_uint(f_down) >> 23) & ((1U << 8) - 1), as_uint(f_down) & frac, (as_uint(f_up) >> 23) & ((1U << 8) - 1), as_uint(f_up) & frac);
    } else {
        printf("0x%x 0x%x", (as_uint(f_down) >> 23) & ((1U << 8) - 1), as_uint(f_down) & frac);
    }
}
