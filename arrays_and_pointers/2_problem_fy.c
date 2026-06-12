#include <assert.h>
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>

int myrand() {
    static unsigned long int seed = 1;
    seed = seed * 1103515245 + 12345;
    return (unsigned int) (seed / 65536) % 32768;
}

int main() {
    int sz;
    scanf("%d", &sz);

    if (sz == 0) {
        printf("0");
        return 0;
    }

    int *arr = malloc(sz * sizeof(int));

    for (int i = 0; i < sz; ++i) {
        scanf("%d", &arr[i]);
    }

    for (int i = sz - 1; i >= 1; --i) {
        const int j = myrand() % (i + 1);
        const int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }

    for (int i = 0; i < sz; ++i) {
        printf("%d ", arr[i]);
    }


    return 0;
}
