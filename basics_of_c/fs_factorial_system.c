#include <assert.h>
#include <stdio.h>

int main()
{
    unsigned int x, y;

    const int res = scanf("%u", &x);
    assert(res == 1);
    int response[100];
    int index = 0;
    unsigned int current_y = 1;
    unsigned int current_factorial = 1;


    while (x >= 0)
    {
        if (x / current_factorial <= y)
        {
            response[index] = x / current_y;
            x = x % current_y;
            current_factorial /= current_y;
            current_y -= 1;
            ++index;
            if (current_y == 0)
            {
                break;
            }
        }
        else
        {
            current_factorial *= current_y + 1;
            current_y *= current_y + 1;
        }
    }

    for (int i = 0; i < index; ++i)
    {
        printf("%u.", response[i]);
    }
}
