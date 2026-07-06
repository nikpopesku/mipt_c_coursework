#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

struct node_t {
    struct node_t *next;
    int data;
};

typedef int (*generator_t)(int);


// определяет длину петли в генераторе
unsigned cycle_len(generator_t gen) {

}

int main() {
    return 0;
}
