#include <assert.h>
#include <stdio.h>

int fibonacci_system(int total, int fibo[10000], int coef[10000])
{
    fibo[0] = 1;
    fibo[1] = 1;
    int counter = 1;
    coef[0] = 0;
    coef[1] = 0;

    while (fibo[counter] < total)
    {
        ++counter;
        fibo[counter] = fibo[counter - 1] + fibo[counter - 2];
        coef[counter] = 0;
    }

    if (fibo[counter] > total)
    {
        --counter;
    }

    const int max_counter = counter;

    while (total > 0)
    {
        if (fibo[counter] <= total)
        {
            total -= fibo[counter];
            coef[counter] = 1;
            counter -= 2;
        }
        else
        {
            --counter;
        }
    }

    return max_counter;
}

int next_turn(const int total, const int possible)
{
    int fibo[10000];
    int coef[10000];
    int max_counter = fibonacci_system(total, fibo, coef);

    for (int i = 0; i < max_counter; ++i)
    {
        if (coef[i] == 1)
        {
            if (fibo[i] <= possible)
            {
                return fibo[i];
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
