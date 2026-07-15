#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node_t {
    struct node_t *next;
    char* data;
    int occurence;
};


int main() {
    unsigned answer;
    unsigned sz1;
    unsigned sz2;
    char* word;
    char* needle;
    char* needle_delimited;
    char* word_delimited;
    struct node_t * tmp;
    struct node_t* node;
    int * occurence;
    int counter = 0;
    struct node_t **bucket = calloc(26, sizeof(struct node_t *));
    int res = scanf("%u", &answer);
    assert(res == 1);

    res = scanf("%u", &sz1);
    assert(res == 1);
    getchar();

    word = calloc(sz1 + 1, sizeof(char));

    fgets(word, sz1 + 1, stdin);

    word_delimited = strtok(word, " \n");

    while (word_delimited != NULL) {
        struct node_t* new_node = calloc(1, sizeof(struct node_t));
        new_node->data = word_delimited;
        new_node->occurence = 1;

        node = bucket[word_delimited[0] - 'a'];

        if (node == NULL) {
            bucket[word_delimited[0] - 'a'] = new_node;
        } else {
            int inserted = 0;
            struct node_t* head = node;
            tmp = node;
            while (node) {
                if (strcmp(node->data, word_delimited) == 0) {
                    ++node->occurence;
                    free(new_node);
                    inserted = 1;
                    break;
                }

                if (strcmp(node->data, word_delimited) < 0) {
                    tmp = node;
                    node = node->next;
                } else {
                    new_node->next = node;
                    if (node == head) {
                        bucket[word_delimited[0] - 'a'] = new_node;
                    } else {
                        tmp->next = new_node;
                    }
                    inserted = 1;
                    break;
                }
            }

            if (!inserted) {
                tmp->next = new_node;
            }
        }

        word_delimited = strtok(NULL, " \n");
    }

    res = scanf("%u", &sz2);
    assert(res == 1);
    getchar();

    occurence = calloc(sz2, sizeof(int));
    needle = calloc(sz2 + 1, sizeof(char));
    fgets(needle, sz2 + 1, stdin);
    needle_delimited = strtok(needle, " \n");

    while (needle_delimited != NULL) {
        node = bucket[needle_delimited[0] - 'a'];

        while (node) {
            if (strcmp(node->data, needle_delimited) == 0) {
                occurence[counter] = node->occurence;
                break;
            }

            node = node->next;
        }

        needle_delimited = strtok(NULL, " \n");
        ++counter;
    }

    for (int i = 0; i < counter; ++i) {
        printf("%d ", occurence[i]);
    }

    free(occurence);
    free(needle);
    free(word);

    for (counter = 0; counter < 26; ++counter) {
        node = bucket[counter];

        while (node) {
            tmp = node->next;
            free(node);
            node = tmp;
        }
    }

    free(bucket);

    return 0;
}
