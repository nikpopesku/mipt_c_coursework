#include <stdio.h>

int main() {
    int sum = 0;
    int ch;

    while ((ch = getchar()) != '\n') {
        sum += ch;
    }

    printf("%d", sum);
    return 0;
}
