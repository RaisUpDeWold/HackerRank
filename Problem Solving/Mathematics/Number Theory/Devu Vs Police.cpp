#include<stdio.h>
#include<iostream>
#include<string.h>
#include<vector>
#include<assert.h>
using namespace std;
typedef long long int ll;
int sieve_par=3162;
int prime[3162] , array[3162],counter=0;
ll inverse(ll a,ll b)                    //b>a
{
    ll Remainder,p0=0,p1=1,pcurr=1,q,m=b;
    while(a!=0)
    {
        Remainder=b%a;
        q=b/a;
        if(Remainder!=0)
        {
            pcurr=p0-(p1*q)%m;
            if(pcurr<0)
                pcurr+=m;
            p0=p1;
            p1=pcurr;
        }
        b=a;
        a=Remainder;
    }
    return pcurr;
}
ll binpow(ll a,ll b,ll mod)
{
    ll ans=1;
    while(b)
        if(b&1){
            ans=(ans*a)%mod;
            b--;
    
        }
        else{    
            a=(a*a)%mod;
            b>>=1;
        }
    return ans%mod;
}
ll CRT(ll mod[],ll rem[],int t)            //t is the number of pairs of rem and mod
{
    ll ans = rem[0],m = mod[0];
    
    for(int i = 1;i < t;++i)
    {
        ll a = inverse(m,mod[i]);
        ll b = inverse(mod[i],m);
        ans = (ans * b * mod[i] + rem[i] * a * m) % (m * mod[i]);
        m *= mod[i];
    }   
    return ans;
}
void sieve()
{
    for(int i=1;i<sieve_par;i++)
        array[i]=1;
    array[0]=0;
    int j;
    for(int i=2;i<=sieve_par;i++)
    {
        if(array[i-1]==1)
        {
            prime[counter]=i;
            for(j=i*i;j<=sieve_par;j+=i)
                array[j-1]=0;
            counter++;
        }
    }
}
int check(ll a,ll b,ll n)
{
    ll ans=1;
    while(b)
        if(b&1){
            ans=ans*a;
            if(ans>n)    return -1;
            b--;
        }
        else{
            a=a*a;
            if(a>n)        return -1;
            b>>=1;    
        }
    return ans;
}
ll solveit(int n1,int k1,int n2,int k2,int m,int p)
{
    ll x=1,y=0;
    if(n1==0){
        if(n2==0 && k2==0 && k1==0)    return 1;
        if(n2==0 && k2==0 && k1!=0)    return 0;
        if(k1==0 || n2==0)    return 1;
        return 0;
    }
    if(n1 % p == 0 ){
        ll ans;
        while(n1%p == 0){
            n1/=p;
            x=x*p;
            y++;
        }
        ans= check(n2,k2,m);
        ans= ans* k1*y;
        if(ans>=0)    ans= check(p,ans,m);
        if(ans<0)    return 0;
        else x= ans;
    }
    ll a=binpow(n2,k2,m-(m/p));
    ll b=binpow(n1,k1,m);
    ll c= binpow(b,a,m);
    return (c*x)%m;
}
int main()
{
    sieve();
    int test,n1,n2,n,k1,k2,t;
    ll mod[15],rem[15],ans;
    //printf("%d is counter\n",counter);    
    scanf("%d",&test);
    assert(test<=10000);
    while(test--){
        scanf("%d%d%d%d%d",&n1,&k1,&n2,&k2,&n);
        assert(n1<=1000000000 &&  k1<=1000000000 && n2<=1000000000 && k2<=1000000000 && n<=10000000);
        assert(n1>=0 && k1>=0 && n2>=0 && k2>=0 && n>=1);
        if(n==1){
            printf("0\n");
            continue;
        }
        t=0;
        for(int i=0;i<counter;i++){
            if(n< prime[i]*prime[i])    break;
            if(n%prime[i]==0){
                mod[t]=1;
                while(n%prime[i]==0){
                    n/=prime[i];
                    mod[t]*=prime[i];
                }
                rem[t]=solveit(n1,k1,n2,k2,mod[t],prime[i]);
                t++;
            }
        }
        if(n>1){
            mod[t]=n;
            rem[t]=solveit(n1,k1,n2,k2,mod[t],n);
            t++;
        }
        printf("%lld\n",CRT(mod,rem,t));
    }
    return 0;
}
