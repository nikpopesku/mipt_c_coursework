#include <assert.h>
#include <stdio.h>
#include <string.h>

static unsigned as_uint(const float f) {
    unsigned u;
    memcpy(&u, &f, sizeof(unsigned));
    return u;
}

int main() {
    float num;
    int res = scanf("%f", &num);
    assert(res == 1);

}
