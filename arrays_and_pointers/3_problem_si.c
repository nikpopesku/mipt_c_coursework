#include <stdio.h>
#include <stdlib.h>

int moveright(int *arr, int key, int last) {
    // TODO: ваш код здесь
}

void inssort(int *arr, int len) {
    int i;
    for (i = 0; i < len; ++i) {
        int key, pos;
        key = arr[i];
        pos = moveright(arr, key, i);
        arr[pos] = key;
    }
}

int main() {
    int sz;
    scanf("%d", &sz);
    int* arr = malloc(sz * sizeof(int));

    for (int i = 0; i < sz; ++i) {
        scanf("%d", &arr[i]);
    }

    free(arr);

    return 0;
}
