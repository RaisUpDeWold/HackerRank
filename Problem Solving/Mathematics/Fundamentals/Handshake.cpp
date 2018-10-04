#include<stdio.h>

int main()
{
    long long T, N, total;
    scanf("%lld",&T);
    while(T--)
    {
        scanf("%lld", &N);
        total = (N * (N - 1)) / 2;
        printf("%lld\n", total);
    }
    return 0;
}
