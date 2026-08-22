#include <assert.h>
#include <stdio.h>
#include <string.h>


static unsigned as_uint(const float f) {
    unsigned u;
    memcpy(&u, &f, sizeof(unsigned));
    return u;
}

static float as_float(const unsigned u) {
    float f;
    memcpy(&f, &u, sizeof(float));

    return f;
}

int main() {
    float num;
    unsigned u, i, e;
    const int res = scanf("%f", &num);
    assert(res == 1);

    u = as_uint(num);
    e = 1;

    for (i = 1; i < 23; i += 1) {
        e <<= 1;
        if (i % 2 == 1) {
            u = u ^ e;
        }
    }

    printf("%.5f\n", as_float(u));
}
