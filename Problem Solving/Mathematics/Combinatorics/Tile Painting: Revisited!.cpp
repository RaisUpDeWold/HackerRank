#include <bits/stdc++.h>
using namespace std ;

#define ft first
#define sd second
#define pb push_back
#define all(x) x.begin(),x.end()

#define ull unsigned long long int
#define ui unsigned int
#define ll long long int
#define vi vector<int>
#define vii vector<pair<int,int> >
#define pii pair<int,int>
#define vl vector<ll>
#define vll vector<pair<ll,ll> >
#define pll pair<ll,ll>
#define mp make_pair

#define sc(x) scanf("%d",&x)
#define sc2(x,y) scanf("%d%d",&x,&y)
#define sc3(x,y,z) scanf("%d%d%d",&x,&y,&z)

#define scll1(x) scanf("%lld",&x)
#define scll2(x,y) scanf("%lld%lld",&x,&y)
#define scll3(x,y,z) scanf("%lld%lld%lld",&x,&y,&z)

#define pr1(x) printf("%d\n",x)
#define pr2(x,y) printf("%d %d\n",x,y)
#define pr3(x,y,z) printf("%d %d %d\n",x,y,z)

#define prll1(x) printf("%lld\n",x)
#define prll2(x,y) printf("%lld %lld\n",x,y)
#define prll3(x,y,z) printf("%lld %lld %lld\n",x,y,z)

#define pr_vec(v) for(int i=0;i<v.size();i++) cout << v[i] << " " ;

#define f_in(st) freopen(st,"r",stdin)
#define f_out(st) freopen(st,"w",stdout)

#define fr(i, a, b) for(i=a; i<=b; i++)
#define fb(i, a, b) for(i=a; i>=b; i--)

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define debug( s ) cout << s << "\n"
#define ASST(x, l, r) assert( x <= r && x >= l )

const int maxn = 1e5 + 10;
const int mod = 1e9 + 7;

int sumN( ll N ) {
    ll N1 = N;
    ll N2 = N1 + 1;
    if( N1 % 2 == 0 ) N1 /= 2;
    if( N2 % 2 == 0 ) N2 /= 2;
    N1 %= mod;
    N2 %= mod;
    return 1LL * N1 * N2 % mod;
}

int rangeSum( ll l, ll r ) {
    l = sumN( l-1 );
    r = sumN( r );
    r -= l;
    if( r < 0 ) r += mod;
    return r;
}

int main() {
    int t; sc( t );
    ASST(t, 1, 10);
    while( t-- ) {
        ll n; scll1( n );
        ASST(n, 1, 10000000000LL);
        vl val1, val2;
        ll x = n;
        int i = 1;
        while( 1LL * i * i <= x ) {
            val1.pb( i );
            if( i != (x / i) ) {
                val2.pb( x / i );
            }
            i ++;
        }
        reverse(all(val2));
        for( auto it: val2 ) val1.pb( it );
        int ans = 0;
        ll l, r;
        l = r = 0;
        for( auto it: val1 ) {
            r = it;
            l ++;
            r = min(r, n-1);
            ll c1, c2;
            c1 = max(0LL, r - l + 1);
            c2 = min(x / l, n-1);
            c1 %= mod;
            c2 %= mod;
            if( l <= r ) {
                ans += 1LL * ( 1LL * c1 * c2 % mod ) * (x % mod) % mod;
                if( ans >= mod ) ans -= mod;
                ans -= 1LL * rangeSum(1, min(n-1, x / l)) * rangeSum(l, r) % mod;
                if( ans < 0 ) ans += mod;
            }
            l = it;
        }    
        ans += n % mod;
        if( ans >= mod ) ans -= mod;
        cout << ans << "\n";    
    }
    return 0;
}
