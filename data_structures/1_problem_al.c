#include <assert.h>
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>

struct node_t {
    struct node_t *next;
    int data;
};

struct node_t *read_list(FILE *inp) {
    struct node_t *odd = calloc(1, sizeof(struct node_t));
    struct node_t *even = calloc(1, sizeof(struct node_t));
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


    even->next = odd;

    return even;
}

void delete_list(struct node_t *top) {
    struct node_t *tmp;
    while (top != NULL) {
        tmp = top->next != NULL ? top->next : NULL;

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
    struct node_t* tmp;

    while (top != NULL) {
        printf("%d ", top->data);
        tmp = top->next ? top->next : NULL;
        top = tmp ? tmp : NULL;
    }

    delete_list(top);

    fclose(f);

    return 0;
}
