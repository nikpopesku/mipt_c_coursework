#include <stdio.h>
#include <stdlib.h>

int moveright(int *arr, const int key, const int last) {
    for (int i = last - 1; i >= 0; --i) {
        if (arr[i] > key) {
            arr[i+1] = arr[i];
        } else {
            return i + 1;
        }
    }

    return 0;
}

// void inssort(int *arr, int len) {
//     int i;
//     for (i = 0; i < len; ++i) {
//         int key, pos;
//         key = arr[i];
//         pos = moveright(arr, key, i);
//         arr[pos] = key;
//     }
// }

int main() {
    int sz;
    scanf("%d", &sz);
    int* arr = malloc(sz * sizeof(int));

    for (int i = 0; i < sz; ++i) {
        scanf("%d", &arr[i]);
    }

    int last;
    scanf("%d", &last);

    int pos = moveright(arr, arr[last], last);

    for (int i = 0; i < sz; ++i) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    printf("%d", pos);

    free(arr);

    return 0;
}
