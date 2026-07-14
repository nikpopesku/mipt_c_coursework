#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node_t {
    struct node_t *next;
    char* data;
};


int main() {
    unsigned answer;
    unsigned sz1;
    unsigned sz2;
    char* word;
    char* word_delimited;
    struct node_t * tmp;
    struct node_t *bucket = calloc(26, sizeof(struct node_t *));
    int res = scanf("%u", &answer);
    assert(res == 1);

    res = scanf("%u", &sz1);
    assert(res == 1);

    word = calloc(sz1 + 1, sizeof(char));

    fgets(word, sz1 + 1, stdin);
    word_delimited = strtok(word, " \n");

    while (word_delimited != NULL) {
        struct node_t* new_node = calloc(1, sizeof(struct node_t));
        new_node->data = word_delimited;

        struct node_t* node = bucket[word_delimited[0] - 'a'];

        if (node == NULL) {
            bucket[word_delimited[0] - 'a'] = new_node;
        } else {
            tmp = node;
            while (node) {
                if (strcmp(node->data, word) == -1) {
                    tmp = node;
                    node = node->next;
                } else {
                    new_node->next = node;
                    tmp->next = new_node;
                    break;
                }
            }
        }

        word_delimited = strtok(NULL, " \n");
    }


    return 0;
}
