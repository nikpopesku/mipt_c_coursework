#include <assert.h>
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>

struct node_t {
    struct node_t *next;
    int data;
};

int list_is_a_loop(struct node_t *top) {
    struct node_t *turtle = top;
    struct node_t *rabbit = top;

    while (rabbit && turtle) {
        rabbit = rabbit->next;

        if (rabbit == turtle) {
            return 1;
        }


        if (rabbit == NULL) {
            return 0;
        }

        rabbit = rabbit->next;
        turtle = turtle->next;

        if (rabbit == turtle) {
            return 1;
        }
    }

    return 0;
}

// определяет длину петли в односвязном списке
// возвращает длину если есть, 0 если петли нет
int loop_len(struct node_t *top);

int main() {
    return 0;
}
