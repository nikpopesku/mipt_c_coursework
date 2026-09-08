#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <stdio.h>
#include <stdlib.h>

// Node for the doubly linked list
typedef struct Node {
    int key;
    int value;
    struct Node* prev;
    struct Node* next;
} Node;

// The LRU Cache structure
typedef struct {
    int capacity;
    int size;
    Node* head; // Most Recently Used (MRU)
    Node* tail; // Least Recently Used (LRU)
    Node** hash_table; // Array of Node pointers (simplified hash map)
    int hash_max;      // Size of the hash table array
} LRUCache;


void insert_at_head(LRUCache* cache, Node* node) {}

void remove_node(Node* node) {}

LRUCache* lru_cache_create(int capacity, int max_key_value) {}

void lru_cache_put(LRUCache* cache, int key, int value) {}

int main() {
    unsigned cell_count, queries_count, i;
    int number;
    int res = scanf("%u", &cell_count);
    assert(res == 1);

    res = scanf("%u", &queries_count);
    assert(res == 1);

    for (i = 0; i < queries_count; ++i) {
        res = scanf("%d", &number);
        assert(res == 1);
    }

    return 0;
}
