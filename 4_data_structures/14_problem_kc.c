#include <string.h>
#include "func.h"

// подсчитать хеш строки от start до fin
int get_hash(const char *start, const char *fin);

// обновить хеш current, удалив из него cprev и добавив в него cnext
// здесь n это pow_mod(R, right - 1, Q)
// возвращает новый хеш
int update_hash(int current, int n, char cprev, char cnext);

// raise n to power k modulo m
unsigned long long pow_mod (unsigned n, unsigned k, unsigned m);

// возвращает номер позиции на которой needle расположена внутри haystack
// или -1 если ничего не найдено
int rabin_karp(const char *needle, const char *haystack) {
    unsigned n, target, cur, count = 0, left = 0, right = strlen(needle);

    target = get_hash(needle, needle + right);
    cur = get_hash(haystack, haystack + right);
    n = pow_mod(R, right - 1, Q);

    while(target != cur && haystack[right] != 0 && strncmp(haystack + left, needle, right - left) != 0) {
        cur = update_hash(cur, n, haystack[left], haystack[right]);
        left += 1;
        right += 1;
    }

    return (target == cur) ? left : -1;
}

int main() {
    return 0;
}
