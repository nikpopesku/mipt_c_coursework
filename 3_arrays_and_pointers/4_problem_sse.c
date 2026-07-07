#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

int main() {
    int sz;

    int res = scanf("%d", &sz);
    assert(res == 1);

    int *arr = calloc(sz, sizeof(int));

    for (int i = 0; i < sz; ++i) {
        res = scanf("%d", &arr[i]);
        assert(res == 1);
    }

    int pos;
    res = scanf("%d", &pos);
    assert(res == 1);

    int delta = pos > 0 ? arr[pos] - arr[pos - 1] : arr[0];
    int new_pos = pos;

    for (int i = pos; i < sz; ++i) {
        if (pos > 0 && arr[i] >= arr[pos - 1] && delta > arr[i] - arr[pos - 1]) {
            delta = arr[i] - arr[pos - 1];
            new_pos = i;
        } else if (pos == 0 && arr[i] < delta) {
            delta = arr[i];
            new_pos = i;
        }
    }

    if (pos != new_pos) {
        const int temp = arr[pos];
        arr[pos] = arr[new_pos];
        arr[new_pos] = temp;
    }

    for (int i = 0; i < sz; ++i) {
        printf("%d ", arr[i]);
    }


    free(arr);
    return 0;
}
