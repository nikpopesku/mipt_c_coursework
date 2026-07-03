#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

struct node_t {
    struct node_t *next;
    int data;
};

struct node_t *read_list(FILE *inp) {
    struct node_t *odd_top = calloc(1, sizeof(struct node_t));
    struct node_t *even_top = calloc(1, sizeof(struct node_t));
    struct node_t *even = even_top;
    struct node_t *odd = odd_top;
    int number;

    while (fscanf(inp, "%d", &number) == 1) {
        if (number % 2) {
            odd->data = number;
            odd->next = calloc(1, sizeof(struct node_t));
            odd = odd->next;
        } else {
            even->data = number;
            even->next = calloc(1, sizeof(struct node_t));
            even = even->next;
        }
    }


    even->next = odd_top;

    return even_top;
}

void delete_list(struct node_t *top) {
    struct node_t *tmp;
    while (top != NULL) {
        tmp = top->next != NULL ? top->next : NULL;
        free(top);

        top = tmp ? tmp : NULL;
    }
}

int main() {
    FILE *f = fopen("1.txt", "r");

    if (f == NULL) {
        printf("Error: Could not open file.\n");
        return 1;
    }


    struct node_t *top = read_list(f);
    struct node_t *tmp, *node = top;

    while (node != NULL) {
        printf("%d ", node->data);
        tmp = node->next ? node->next : NULL;
        node = tmp ? tmp : NULL;
    }

    delete_list(top);

    fclose(f);

    return 0;
}
