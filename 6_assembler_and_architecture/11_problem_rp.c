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
    unsigned numerator, denominator;
    float f_down, f_up;
    int res = scanf("%u", &numerator);
    assert(res == 1);
    res = scanf("%u", &denominator);
    assert(res == 1);

    fesetround(FE_DOWNWARD);
    f_down = (float) numerator / denominator;

    fesetround(FE_UPWARD);
    f_up = (float) numerator / denominator;

    if (f_down != f_up) {
        printf("%x %x", as_uint(f_down), as_uint(f_up));
    } else {
        printf("%x", as_uint(f_down));
    }
}
