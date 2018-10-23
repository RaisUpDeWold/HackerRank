#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
    
ll sieve(ll a[],ll b[],ll n)
{
    ll i,k,j;
    for(i=0;i<n;i++)
    {        
       a[i]=i,b[i]=0;
    }
    for (j=2;j*j<n;j++)
    { 
       k=j;
       if(a[j]!=0)
       { 
           while(k*j<n)
           {                
               a[k*j]=0;
               k=k+1;
           }
       }
    }
    i=2;j=0;
    while(i<n)
    {
       if(a[i]!=0)
       {
           b[j]=a[i];
           j++;
       }
       i++;
    }
    return j;
}
    
ll gcd(ll a,ll b)
{
   ll d;
   a=a>=0?a:-a;
   b=b>=0?b:-b;
   while(b!=0)
   {
       d=a%b;
       a=b;
       b=d;
   }
   return a;
}
    
ll abmodP(ll a, ll b,ll mod)
{
   ll aprod = a;
   ll ans = 0;
   while(b > 0) {
       if(b & 1) ans = (ans + aprod) % mod;
       b = b >> 1;
       aprod = (aprod << 1) % mod;
   }
   return ans;
}
long long int power(long long int a,long long int b,long long int c)//To calculate A^B%C
{
   long long int res=1,apower=a;
   while(b > 0)
   {
       if(b%2 == 1)
       {
           res=abmodP(res,apower,c);
       }
       apower = abmodP(apower,apower,c);
       b=b/2 ;
   }
  
   return res%c;
}
    
    
    
ll a[100005],b[100005];
    
int main()
{
   ll n = 100000;
   ll k = sieve(a,b,n);
   ll t,x;
   ll i,j;
   scanf("%lld",&t);
   while(t--)
   {
       ll d[20][3];
       scanf("%lld",&x);
       if(x==0)
           cout << 0 << endl;
       else if(x==1)
           cout << 2 << endl;
       else
       {
           x = x*9;
           ll len=0;
           for(i=0;b[i]*b[i] <= x && i<k ; i++)
           {
               ll count=0;
               if(x%b[i]==0)
               {
                   ll an1=1;
                   d[len][0]=b[i];
                   while(x%b[i]==0)
                       x=x/b[i],count+=1,an1*=b[i];
                       d[len][1]=count,d[len][2]=an1;
                   len+=1;
               }
           }
           if(x!=1)
               d[len][0]=x,d[len][1]=1,d[len][2]=x,len=len+1;
           ll c2=0,c5=0,c3=0;
           if(d[0][0]==2)
               c2=d[0][1];
           if(d[0][0]==5)
               c5=d[0][1];
           if(len > 1 && d[1][0]==5)
               c5=d[1][1];
           if(len > 2 && d[2][0]==5)
               c5=d[2][1];
           ll y=max(c5,c2-2);
           ll e[20];
           ll len1=0;
           for(i=0;i<len;i++)
           {
               if(d[i][0]!=2 && d[i][0]!=5)
               {
                   ll a1 = d[i][2]/d[i][0];
                   a1 = a1 * (d[i][0]-1);
                   ll  min1=a1;
                   for(j=1;j*j<a1;j++)
                   {
                       if(a1%j==0)
                       {
                           ll po= power((ll)10,j,d[i][2]);
                           if(po < 0)
                                   po+=d[i][2];
                           if(po==1)
                               min1 = min(j,min1);
                           else
                           {
                               po= power((ll)10,(a1/j),d[i][2]);
                               if(po < 0)
                                   po+=d[i][2];
                               if(po==1)
                                   min1 = min(a1/j,min1);
                           }
    
                       }
                   }
                   e[len1]=min1;
                   len1+=1;
               }
           }
           ll lcm = e[0];
           for(i=1;i<len1;i++)
           {
               lcm = (lcm * e[i])/gcd(lcm,e[i]);   
           }
           printf("%lld\n",2*lcm + y);    
       }
       
   }
    
   return 0;
}
