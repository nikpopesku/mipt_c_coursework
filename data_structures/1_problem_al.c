#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

struct node_t {
    struct node_t *next;
    int data;
};

struct node_t *read_list(FILE *inp) {
    struct node_t *odd_top = NULL;
    struct node_t *even_top = NULL;
    struct node_t *even = NULL;
    struct node_t *odd = NULL;
    int number;

    while (fscanf(inp, "%d", &number) == 1) {
        if (number % 2 == 1) {
            if (odd == NULL) {
                odd = calloc(1, sizeof(struct node_t));
                odd_top = odd;
            } else {
                odd->next = calloc(1, sizeof(struct node_t));
                odd = odd->next;
            }
            odd->data = number;
        } else {
            if (even == NULL) {
                even = calloc(1, sizeof(struct node_t));
                even_top = even;
            } else {
                even->next = calloc(1, sizeof(struct node_t));
                even = even->next;
            }
            even->data = number;
        }
    }


    if (even_top != NULL && odd_top != NULL) {
        even->next = odd_top;
    } else {
        even_top = even_top == NULL ? odd_top : even_top;
    }

    even = NULL;
    odd = NULL;
    odd_top = NULL;

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
    struct node_t *tmp;
    const struct node_t *node = top;

    while (node != NULL) {
        printf("%d ", node->data);
        tmp = node->next ? node->next : NULL;
        node = tmp ? tmp : NULL;
    }

    delete_list(top);

    fclose(f);

    return 0;
}
