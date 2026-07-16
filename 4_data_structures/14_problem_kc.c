#include <string.h>
#include "func.h"

int rabin_karp(const char *needle, const char *haystack) {
    unsigned n, target, cur, left = 0, right = strlen(needle);

    target = get_hash(needle, needle + right);
    cur = get_hash(haystack, haystack + right);
    n = pow_mod(R, right - 1, Q);

    while(haystack[right] != 0 && (target != cur || strncmp(haystack + left, needle, right - left) != 0)) {
        cur = update_hash(cur, n, haystack[left], haystack[right]);
        left += 1;
        right += 1;
    }

    return (target == cur) && strncmp(haystack + left, needle, right - left) == 0 ? left : -1;
}
