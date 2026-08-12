#include <stdio.h>

#include "7_problem_ags_caller.c"

int main() {
    printf("%d\n", caller(2, 1, 10)); // 2
    printf("%d\n", caller(2, 4, 10)); // 6
    printf("%d\n", caller(2, 5, 10)); // 2
}