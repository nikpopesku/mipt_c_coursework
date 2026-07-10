#include <assert.h>
#include <stdio.h>
#include <stdlib.h>


int main() {
    FILE fptr = fopen("input.txt", "r");

    if (fptr == NULL) { // 3. Check for errors
        printf("Error opening file!\n");
        return 1;
    }

    fclose(fptr);

    return 0;
}
