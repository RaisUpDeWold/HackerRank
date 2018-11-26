#include <bits/stdc++.h>

using namespace std;
struct _ { ios_base::Init i; _() { cin.sync_with_stdio(0); cin.tie(0); } } _;

const long long mod = 1000000007;

long long gcd(long long a, long long b)
{
    if(a < 0) a = -a; if(b < 0) b = -b;
    return b ? gcd(b, a % b) : a;
}
    
int main()
{
    int t; cin >> t;
    while(t--)
    {
        long long p, q, r;
        cin >> p >> q >> r;
        assert(gcd(p, q) == 1);
        assert(gcd(p, r) == 1);
        assert(gcd(q, r) == 1);
        p %= mod, q %= mod, r %= mod;
    
        long long ret = (p * q) % mod;
        ret += (q * r) % mod;
        if(ret >= mod) ret -= mod;
        ret += (r * p) % mod;
        if(ret >= mod) ret -= mod;
    
        if(--ret < 0) ret += mod;
        if(ret & 1) ret += mod;
    
        cout << (ret >> 1) << '\n';
    }
    return 0;
}
