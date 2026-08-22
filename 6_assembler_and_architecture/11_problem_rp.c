#include <assert.h>
#include <fenv.h>
#include <stdio.h>


int main() {
    unsigned numerator, denominator;
    int res = scanf("%u", &numerator);
    assert(res == 1);
    res = scanf("%u", &denominator);
    assert(res == 1);

    fesetround(FE_DOWNWARD);
    printf("%f", (float) numerator / denominator);

    fesetround(FE_UPWARD);
    printf("%f", (float) numerator / denominator);
}
