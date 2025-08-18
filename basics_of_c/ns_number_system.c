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
    unsigned int x, y;

    const int res = scanf("%d %d %d", &x, &y);
    assert(res == 2);


    const int index = de_solution(coef);

    printf("%d %d", x, y);
}
