#include <assert.h>
#include <stdio.h>

int main()
{
    unsigned int x;

    const int res = scanf("%u", &x);
    assert(res == 1);
    int response[100];
    int index = 0;
    unsigned int y = 1;
    unsigned int factorial = 1;


    while (x >= 0)
    {
        if (x / factorial <= y)
        {
            response[index] = x / factorial;
            x = x % factorial;
            factorial /= y;
            y -= 1;
            ++index;
            if (y == 0)
            {
                break;
            }
        }
        else
        {
            factorial *= y + 1;
            y += 1;
        }
    }

    for (int i = 0; i < index; ++i)
    {
        printf("%u.", response[i]);
    }
}
