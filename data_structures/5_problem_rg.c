#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

struct node_t {
    struct node_t *next;
    int data;
};

typedef int (*generator_t)(int);

unsigned cycle_len(generator_t gen) {
    const int first = gen(0);
    int next = first;
    unsigned counter = 1;

    while (next != first) {
        ++counter;
        next = gen(next);
    }

    return counter;
}

int main() {
    return 0;
}
