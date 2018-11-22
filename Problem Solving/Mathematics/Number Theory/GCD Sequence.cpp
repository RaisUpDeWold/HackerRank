#include<bits/stdc++.h>

using namespace std;


#define ll long long int 
#define MOD 1000000007

ll mu[666666];
ll fact[1111111];

void pre(long long PP)
{
    long long i,j;
    mu[1]=1;
    for(i=1;i<=PP;++i) {
       for(j=2*i;j<=PP;j+=i) {
           mu[j]-=mu[i];
       }
    }
    return;
}

ll pw(ll a , ll b)
{
    if(b==0)
        return 1;
    if(b%2 == 0)
    {
        ll temp = pw(a,b/2);
        return (temp*temp)%MOD;
    }
    else
    {
            ll temp = pw(a,b/2);
            temp = (temp*temp)%MOD;
            return (temp*a)%MOD;
    }
}

ll func(ll n , ll r) // n+r-1 ... n
{
    ll ans = fact[n+r-1];
    ans = (ans*pw(fact[r],MOD-2))%MOD;
    ans = (ans*pw(fact[n-1],MOD-2))%MOD;
    return ans;
}


int main()
{
    int t;
    cin>>t;
    pre(555555);
    fact[0] = 1;
    for(ll i =1 ; i< 1111111 ; i++)
        fact[i] = (fact[i-1]*i) %MOD;
   // cout<<func(3,2)<<endl;
    while(t--)
    {
        long long int n,k;
        cin>>n>>k; //1.....N and length K
        assert(1<=n && n<=100000);                    
        assert(1<=k && k<= 100000);
        ll ans = 0 ;
        for(ll i =1 ; i<= n ; i++)
            ans = (ans + MOD + func((n/i), k)*mu[i])%MOD;
        cout<<ans<<endl;        
    }
    return 0;
}
