#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

struct node_t {
    struct node_t *next;
    char* data;
};


int main() {
    unsigned answer;
    unsigned sz1;
    unsigned sz2;
    char* word = NULL;
    struct node_t *bucket = calloc(26, sizeof(struct node_t));
    int res = scanf("%u", &answer);
    assert(res == 1);

    res = scanf("%u", &sz1);
    assert(res == 1);

    while (scanf("%ms", &word) == 1) {
        struct node_t* node = calloc(1, sizeof(struct node_t));
        node->data = word;
        free(word);
    }


    return 0;
}
