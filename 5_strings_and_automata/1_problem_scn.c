#include <stdio.h>

int main() {
    int sum = 0;
    int ch;

    while (scanf("%d", &ch) == 1) {
        sum += ch;
    }

    printf("%d", sum);
    return 0;
}
