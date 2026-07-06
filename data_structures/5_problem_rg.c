#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

struct node_t {
    struct node_t *next;
    int data;
};

typedef int (*generator_t)(int);

int genit1(int x) {
    return (x + 2) % 5;
}

int genit2(int x) {
    return (x + 2) % 5 + 1;
}

int genit3(int x) {
    return (3 * x + 2) % 5 + 4;
}

unsigned cycle_len(generator_t gen) {
    const int first = gen(0);
    int next = gen(first);
    unsigned counter = 1;

    while (next != first) {
        ++counter;
        next = gen(next);
    }

    return counter;
}

int main() {
    printf("%d\n", cycle_len(genit1));
    printf("%d\n", cycle_len(genit2));
    printf("%d\n", cycle_len(genit3));
    return 0;
}
