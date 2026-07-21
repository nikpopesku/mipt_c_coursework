#include <assert.h>
#include <stdio.h>



int main() {
    char ch;
    int position = 1;

    while ((ch = getchar()) != EOF) {
        switch (ch) {
            case 'a':
                switch (position) {
                    case 3:
                    case 4:
                        position = 5;
                }
                break;
            case 'b':
                switch (position) {
                    case 1:
                        position = 2;
                        break;
                    case 3:
                        position = 4;
                        break;
                }
                break;
            case 'c':
                switch (position) {
                    case 1:
                        position = 5;
                        break;
                    case 2:
                    case 4:
                        position = 3;
                }
                break;
            default:
                printf("%d", position == 2 || position == 3 || position == 4);
                return 0;
        }
    }

    printf("%d", position == 2 || position == 3 || position == 4);

    return 0;
}
