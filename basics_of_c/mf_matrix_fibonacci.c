#include <assert.h>
#include <stdio.h>

void solve(int x00, int x01, int x10, int x11, int n, int m)
{
}

int main()
{
    int x00, x01, x10, x11, n, m;

    const int res = scanf("%d %d %d %d %d %d", &x00, &x01, &x10, &x11, n, m);
    assert(res == 6);

    solve(x00, x01, x10, x11, n, m);

    return 0;
}
