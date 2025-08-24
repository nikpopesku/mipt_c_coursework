#include <assert.h>
#include <stdio.h>

typedef struct
{
    int x00;
    int x01;
    int x10;
    int x11;
} Matrix;

Matrix solve(const int x00, const int x01, const int x10, const int x11, const int n, const int m)
{
    if (n == 1)
    {
        Matrix response;
        response.x00 = x00;
        response.x10 = x10;
        response.x01 = x01;
        response.x11 = x11;

        return response;
    }
    if (n % 2 == 0)
    {
        const Matrix value = solve(x00, x01, x10, x11, n / 2, m);

        Matrix response;
        response.x00 = value.x00 * value.x00 + value.x01 * value.x10;
        response.x10 = x10;
        response.x01 = x01;
        response.x11 = x11;

        return response;
    }

    const Matrix value = solve(x00, x01, x10, x11, n - 1, m);

    Matrix response;
    response.x00 = value.x00 * value.x00 + value.x01 * value.x10;
    response.x10 = x10;
    response.x01 = x01;
    response.x11 = x11;

    return response;
}

int main()
{
    int x00, x01, x10, x11, n, m;

    const int res = scanf("%d %d %d %d %d %d", &x00, &x01, &x10, &x11, &n, &m);
    assert(res == 6);

    x00 = x00 % m;
    x01 = x01 % m;
    x10 = x10 % m;
    x11 = x11 % m;

    const Matrix response = solve(x00, x01, x10, x11, n, m);

    printf("%d %d %d %d", response.x00, response.x01, response.x10, response.x11);

    return 0;
}
