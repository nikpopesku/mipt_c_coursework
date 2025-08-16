#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

int de_solution(int coef[1000][4])
{
    int index = 2;

    while (coef[index - 2][0] % coef[index - 1][0] != 0)
    {
        coef[index][0] = coef[index - 2][0] % coef[index - 1][0];
        coef[index][1] = coef[index - 2][0] / coef[index - 1][0];
        coef[index][2] = coef[index - 2][2] - coef[index][1] * coef[index - 1][2];
        coef[index][3] = coef[index - 2][3] - coef[index][1] * coef[index - 1][3];
        ++index;
    }

    return index - 1;
}

int main()
{
    int a, b, c;

    const int res = scanf("%d %d %d", &a, &b, &c);
    assert(res == 3);

    int coef[1000][4];

    coef[0][0] = abs(a);
    coef[0][2] = 1;
    coef[0][3] = 0;
    coef[1][0] = abs(b);
    coef[1][2] = 0;
    coef[1][3] = 1;

    const int index = de_solution(coef);

    if (c % coef[index][1] != 0)
    {
        printf("NONE");

        return 0;
    }

    const int x = a < 0 ? -coef[index][2] : coef[index][2];
    const int y = b < 0 ? -coef[index][3] : coef[index][3];


    printf("%d %d", x, y);
}
