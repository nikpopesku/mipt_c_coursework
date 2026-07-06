#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

struct node_t {
    struct node_t *next;
    int data;
};

int list_is_a_loop(const struct node_t *turtle, const struct node_t *rabbit) {
    if (rabbit == NULL) return 0;

    do {
        rabbit = rabbit->next;

        if (rabbit == turtle) return 1;

        if (rabbit == NULL) return 0;

        rabbit = rabbit->next;
        turtle = turtle->next;

        if (rabbit == turtle) return 1;
    } while (rabbit && turtle);

    return 0;
}

int loop_len(struct node_t *top) {
    const struct node_t *rabbit = top;
    const struct node_t *turtle = top;
    if (list_is_a_loop(turtle, rabbit) == 0) return 0;

    int counter = 0;

    do {
        ++counter;
        rabbit = rabbit->next->next;
        turtle = turtle->next;
    } while (turtle != rabbit);

    return counter;
}

static struct node_t *make_node(int data) {
    struct node_t *n = malloc(sizeof(struct node_t));
    n->data = data;
    n->next = NULL;
    return n;
}

static void free_list_no_loop(struct node_t *top) {
    while (top) {
        struct node_t *next = top->next;
        free(top);
        top = next;
    }
}

int main() {
    struct node_t *n1;
    struct node_t *n2;
    struct node_t *n3;
    struct node_t *n4;
    int result;

    // Пример 1: 2 -> 4 -> 6 -> 1, петли нет
    n1 = make_node(2);
    n2 = make_node(4);
    n3 = make_node(6);
    n4 = make_node(1);
    n1->next = n2;
    n2->next = n3;
    n3->next = n4;

    result = loop_len(n1);
    printf("Пример 1: %d (ожидалось 0)\n", result);
    assert(result == 0);

    free_list_no_loop(n1);

    // Пример 2: 2 -> 4 -> 6 -> (обратно на 2), длина петли 3
    n1 = make_node(2);
    n2 = make_node(4);
    n3 = make_node(6);
    n1->next = n2;
    n2->next = n3;
    n3->next = n1;

    result = loop_len(n1);
    printf("Пример 2: %d (ожидалось 3)\n", result);
    assert(result == 3);

    n3->next = NULL;
    free_list_no_loop(n1);

    // Пример 3: 2 -> 4 -> 6 -> (обратно на 4), длина петли 2
    {
        struct node_t *n1 = make_node(2);
        struct node_t *n2 = make_node(4);
        struct node_t *n3 = make_node(6);
        n1->next = n2;
        n2->next = n3;
        n3->next = n2;

        int result = loop_len(n1);
        printf("Пример 3: %d (ожидалось 2)\n", result);
        assert(result == 2);

        n3->next = NULL;
        free_list_no_loop(n1);
    }

    // Пример 4: 2 -> 4 -> 6 -> (обратно на 6), длина петли 1
    {
        struct node_t *n1 = make_node(2);
        struct node_t *n2 = make_node(4);
        struct node_t *n3 = make_node(6);
        n1->next = n2;
        n2->next = n3;
        n3->next = n3;

        int result = loop_len(n1);
        printf("Пример 4: %d (ожидалось 1)\n", result);
        assert(result == 1);

        n3->next = NULL;
        free_list_no_loop(n1);
    }

    printf("Все тесты пройдены.\n");
    return 0;
}
