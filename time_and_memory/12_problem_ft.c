#include <assert.h>
#include <stdio.h>

solve(unsigned long long P)
{

}

int main()
{
    unsigned long long P= 0;

    const int res = scanf("%llu", &P);
    assert(res == 1);

    const int answer = solve(P);

    printf("%d", answer);

    return 0;
}