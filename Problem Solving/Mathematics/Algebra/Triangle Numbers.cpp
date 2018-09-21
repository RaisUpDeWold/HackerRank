#include<stdio.h>

int main()
{
    int t, n, result;
    scanf("%d", &t);
    while(t--)
    {
        scanf("%d", &n);
        if(n%4 == 1)
            result = 2;
        if(n%4 == 2)
            result = 4;
        if(n%4 == 3)
            result = 2;
        if(n%4==0)
            result = 3;
        printf("%d\n", result);
    }
    return 0;
}
