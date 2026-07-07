#include <assert.h>
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>

int main() {
    int sz;
    const int res = scanf("%d", &sz);
    assert(res == 1);
    int mn = INT_MAX;
    int mx = INT_MIN;

    if (sz == 0) {
        printf("0 0");

        return 0;
    }

    int *arr = malloc(sz * sizeof(int));
    for (int i = 0; i < sz; i++) {
        scanf("%d", &arr[i]);
        if (arr[i] > mx) {
            mx = arr[i];
        }

        if (arr[i] < mn) {
            mn = arr[i];
        }
    }

    printf("%d %d", mn, mx);

    free(arr);

    return 0;
}
