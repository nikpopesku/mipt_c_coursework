#include <assert.h>
#include <stdio.h>

void factorial_system(int total, int factorial_array[1000])
{
    int index = 0;
    int step = 1;
    int factorial = 1;

    while (total >= 0)
    {
        if (total / factorial <= step)
        {
            factorial_array[index] = total / factorial;
            total = total % factorial;
            factorial /= step;
            step -= 1;
            ++index;
            if (step == 0)
            {
                break;
            }
        }
        else
        {
            factorial *= step + 1;
            step += 1;
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
