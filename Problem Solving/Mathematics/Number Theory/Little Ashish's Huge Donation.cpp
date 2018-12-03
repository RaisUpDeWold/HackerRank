#include<cstdio>
#include<iostream>
#include<cstdlib>
#include<cmath>
#include<stdio.h>
#include<math.h>
using namespace std;
#define ll long long int
#define FOR(i,a,b) for(i= (int )a ; i < (int )b ; ++i)
#define rep(i,n) FOR(i,0,n)
#define si(n) scanf("%d",&n)
#define sl(n) scanf("%lld",&n)
int main()
{
    int t,i;
    ll sum=0,low,high,mid,x,calc,calc1;
    si(t);
    while(t--)
    {
        sl(x);
        low=0;
        high=1000000;
        while(low<=high)
        {
            mid=(low+high)/2;
            calc=(mid*(mid+1)*(2*mid+1))/6;
            calc1=((mid+1)*(mid+2)*(2*(mid+1)+1))/6;
            if(calc<=x && calc1>x)
            {
                printf("%lld\n",mid);
                break;
            }
            else if(calc<x)
            {
                low=mid+1;
            }
            else
                high=mid-1;
        }
    }
    return 0;
}
