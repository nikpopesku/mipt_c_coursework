#include <assert.h>
#include <stdio.h>

int next_turn(const int total, const int possible)
{
    int last = 0, penultimate = 1;

    while (last + penultimate <= possible)
    {
        const int value = last + penultimate;
        last = penultimate;
        penultimate = value;
    }


    return total - penultimate;
}

int main()
{
    int total, possible;

    const int res = scanf("%d %d", &total, &possible);
    assert(res == 2);

    next_turn(total, possible);

    const int next = next_turn(total, possible);
    printf("%d\n", next);

    return 0;
}
