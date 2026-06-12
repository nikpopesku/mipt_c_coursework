#include <assert.h>
#include <limits.h>
#include <stdio.h>

int main()
{
    int sz;
    const int res = scanf("%d", &sz);
    assert(res == 1);
    int mn = INT_MAX;
    int mx = INT_MIN;

    if (sz == 0) {
        printf("0 0");

        return 0;
    }

    int val;

    for (int i = 0; i < sz; ++i) {
        scanf("%d", &val);
        if (val > mx) {
            mx = val;
        }

        if (val < mn) {
            mn = val;
        }
    }

    printf("%d %d", mn, mx);

    return 0;
}
