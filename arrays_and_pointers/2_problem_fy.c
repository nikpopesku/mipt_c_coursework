#include <assert.h>
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>

int myrand() {
    static unsigned long int seed = 1;
    seed = seed * 1103515245 + 12345;
    return (unsigned int)(seed / 65536) % 32768;
}

int main() {
    int sz;
    scanf("%d", &sz);

    int *arr = malloc(sz * sizeof(int));

    for (int i = 0; i < sz; ++i) {
        scanf("%d", &arr[i]);
    }

    for (int i = 0; i < sz; ++i) {
        printf("%d ", arr[i]);
    }


    return 0;
}
