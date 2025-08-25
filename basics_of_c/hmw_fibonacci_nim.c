#include <assert.h>
#include <stdio.h>


int next_turn(int total, int possible) {
    return 5;
}

int main()
{
    int total, possible;

    const int res = scanf("%d %d", &total, &possible);
    assert(res == 2);

    next_turn(total, possible);

    int next = next_turn(total, possible);
    printf("%d\n", next);

    return 0;
}
