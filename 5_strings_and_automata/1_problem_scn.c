#include <stdio.h>

int main() {
    int sum = 0;
    char ch;

    while ((ch = getchar()) != EOF) {
        sum += ch;
    }

    printf("%d", sum);
    return 0;
}
