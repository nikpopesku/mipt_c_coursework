#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

struct node_t {
    struct node_t *next;
    int data;
};

struct node_t * list_is_a_loop(struct node_t *turtle, struct node_t * rabbit) {
    if (rabbit == NULL) return 0;

    do {
        rabbit = rabbit->next;

        if (rabbit == turtle) return rabbit;

        if (rabbit == NULL) return 0;

        rabbit = rabbit->next;
        turtle = turtle->next;

        if (rabbit == turtle) return rabbit;
    } while (rabbit && turtle);

    return NULL;
}

// определяет длину петли в односвязном списке
// возвращает длину если есть, 0 если петли нет
int loop_len(struct node_t *top) {
    struct node_t * rabbit = list_is_a_loop(top, top);
    if (rabbit == NULL) return 0;

    struct node_t * turtle = top;
    int counter = 0;

    while (turtle != rabbit) {
        ++counter;
        rabbit = rabbit->next;
        turtle = turtle->next;
    }

    return counter;
}

int main() {
    return 0;
}
