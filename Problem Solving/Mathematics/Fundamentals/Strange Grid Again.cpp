#include<stdio.h>

int main()
{
    long long r,c,ans;
    scanf("%lld %lld",&r,&c);
    if(r%2 == 1)
        ans = ((r - 1)/2) * 10;
    else
        ans = ((r - 1) / 2) * 10 + 1;
    ans=ans + 2 * (c - 1);
    printf("%lld\n",ans);
    return 0;
}
