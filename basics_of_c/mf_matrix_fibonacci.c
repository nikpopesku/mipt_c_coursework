#include <assert.h>
#include <stdio.h>

void solve(int* x00, int* x01, int* x10, int* x11, const int n, const int m)
{
    if (n == 1)
    {
        return;
    }

    if (n % 2 == 0)
    {
        solve(x00, x01, x10, x11, n / 2, m);
    }
    else
    {
        solve(x00, x01, x10, x11, n - 1, m);
    }
    const int updated_x00 = ((*x00) * (*x00) % m + (*x01) * (*x10) % m) % m;
    const int updated_x01 = ((*x00) * (*x01) % m + (*x01) * (*x11) % m) % m;
    const int updated_x10 = ((*x10) * (*x00) % m + (*x11) * (*x10) % m) % m;
    const int updated_x11 = ((*x10) * (*x01) % m + (*x11) * (*x11) % m) % m;

    *x00 = updated_x00;
    *x01 = updated_x01;
    *x10 = updated_x10;
    *x11 = updated_x11;
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

    solve(&x00, &x01, &x10, &x11, n, m);

    printf("%d %d %d %d", x00, x01, x10, x11);

    return 0;
}
