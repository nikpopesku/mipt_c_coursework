#include <assert.h>
#include <stdio.h>


void solve(unsigned char a[100000], const int k, const int N)
{
    if (N < k * 8)
    {
        unsigned char value = 1;
        value = value << N % 8;
        a[N / 8] = a[N / 8] ^ value;
    }

    for (int i = 0; i < k; ++i)
    {
        printf("%hhu ", a[i]);
    }
}


int main()
{
    int k = 0, N = 0;
    unsigned char number;
    unsigned char a[100000];

    int res = scanf("%d", &k);
    assert(res == 1);

    for (int i = 0; i < k; ++i)
    {
        res = scanf("%hhu", &number);
        assert(res == 1);
        a[i] = number;
    }


    res = scanf("%d", &N);
    assert(res == 1);


    solve(a, k, N);

    return 0;
}
