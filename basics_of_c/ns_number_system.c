#include <assert.h>
#include <stdio.h>

int main()
{
    unsigned int x, y;

    const int res = scanf("%u %u", &x, &y);
    assert(res == 2);
    int response[100];
    int index = 0;
    unsigned int current_y = y;


    while (x >= 0)
    {
        if (x / current_y < y)
        {
            response[index] = x / current_y;
            x = x % current_y;
            current_y = current_y / y;
            ++index;
            if (current_y == 0)
            {
                break;
            }

        }
        else
        {
            current_y *= y;
        }
    }

    for (int i = 0; i < index; ++i)
    {
        printf("%u", response[i]);
    }
}
