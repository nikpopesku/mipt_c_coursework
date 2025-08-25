#include <assert.h>
#include <stdio.h>

void factorial_system(int total, int factorial_array[1000])
{
    int f[10000];
    int coef[10000];
    f[0] = 1;
    f[1] = 1;
    int counter = 1;
    coef[0] = 0;
    coef[1] = 0;

    while (f[counter] < total)
    {
        ++counter;
        f[counter] = f[counter - 1] + f[counter - 2];
        coef[counter] = 0;
    }

    if (f[counter] > total)
    {
        --counter;
    }

    const int max_counter = counter;

    while (total > 0)
    {
        if (f[counter] <= total)
        {
            total -= f[counter];
            coef[counter] = 1;
            counter -= 2;
        }
        else
        {
            --counter;
        }
    }

}

int next_turn(const int total, const int possible)
{
    int factorial[1000];
    for (int i = 0; i < 1000; ++i) factorial[i] = 0;
    factorial_system(total, factorial);

    for (int i = 0; i < 1000; ++i)
    {
        if (factorial[i] == 1)
        {
            if (i <= possible)
            {
                return i;
            }

            return 1;
        }
    }

    return 1;
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
