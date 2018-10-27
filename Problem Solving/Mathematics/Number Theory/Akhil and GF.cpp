#include<bits/stdc++.h>

using namespace std;

long long int power(long long int a, long long int b, long long int c)
{
    if(b==0) 
        return 1;
    if(b==1)
        return a%c;
    if(b%2 == 0)
    {
        long long int temp = power(a,b/2,c);
        return (temp*temp)%c;
    }
    else
    {
        long long int temp = power(a,b/2,c);
        temp = (temp*temp)%c;
        return (temp*a)%c;
    }
}

long long int func(long long int n, long long int m)
{
    if(n< 6)
    {
        if(n==0)
            return 0;
        if(n==1)    
            return 1;
        if(n==2)
            return 11%m;
        if(n==3)
            return 111%m;
        if(n==4)
            return 1111%m;
        if(n==5)
            return 11111%m;
    }
    if(n%2 == 0)
    {
        long long int temp = func(n/2 , m)%m;
        long long int temp1 = (power(10,n/2,m)*temp + temp)%m;
        return temp1;
    }
    else
    {
        long long int temp = func(n/2 , m)%m;
        long long int temp1 = (power(10,n/2+1,m)*temp + temp*10 + 1)%m;
        return temp1;
    }
}

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        long long int n,m;    
        cin>>n>>m;
        assert(n > 0);
        assert(m > 0);
        cout<<func(n,m)<<endl;
    }
    return 0;
}
