#include <stdio.h>
#include <math.h>
#define C 2000000
#define mod 1000000007
#define ll long long
#include <map>
using namespace std;

ll Gs[C+1];
map<ll,ll> _G;

ll cb(ll n) { 
    n %= mod;
    return n * n % mod * n % mod;
}
ll G(ll n) {
    if (n <= C) return Gs[n];
    if (_G.find(n) == _G.end()) {
        ll s = cb(2*n+1) - 1;
        int sq = int(sqrt(n));
        int nsq = n/sq;
        for (int j = 2; j <= nsq; j++) {
            s -= G(n/j);
        }
        s %= mod;
        ll pv = n;
        for (int v = 1; v < sq; v++) {
            ll nx = n/(v+1);
            s -= Gs[v] * (pv - nx);
            s %= mod;
            pv = nx;
        }
        _G[n] = s;
        return s;
    }
    return _G[n];
}

ll max(ll a, ll b) { return a > b ? a : b; }

int main() {
    Gs[0] = 2;
    for (int n = 1; n <= C; n++) {
        Gs[n] = (Gs[n-1] + 48*n - 24) % mod;
    }
    Gs[0] = 0;
    for (int n = 1; n <= C; n++) {
        for (int j = n << 1; j <= C; j += n) {
            Gs[j] -= Gs[n];
        }
        Gs[n] += Gs[n-1];
        Gs[n] %= mod;
    }

    int z;
    scanf("%d", &z);
    while (z--) {
        ll n;
        int m, d;
        scanf("%lld%d%d", &n, &m, &d);

        ll c1 = 0, c2 = 0;
        int m1d = (m-1)/d;
        if (m1d+1 <= n/d) {
            int sq = int(sqrt(n/d));
            int nsq = n/sq;
            int nsqd = nsq/d*d, nsq1d = (nsq-1)/d*d;
            for (ll q = (m1d+1)*d; q <= nsq1d; q+=d) {
                c1 += G(n/q);
                c2 += G(n/(q+1));
            }
            for (ll q = max(m1d*d,nsq1d)+d; q <= nsqd; q+=d) {
                c1 += G(n/q);
            }
            for (int v = 1; v < sq; v++) {
                ll g = Gs[v], up, dn;
                ll nv = n/v;
                ll nv1 = n/(v+1);
                up = nv/d;
                dn = max(m1d, nv1/d);
                if (up > dn) c1 += g * (up - dn);
                up = (nv-1)/d;
                dn = max(m1d, (nv1-1)/d);
                if (up > dn) c2 += g * (up - dn);
            }
        }
        ll c = (c1 - c2) % mod;
        if (c < 0) c += mod;
        printf("%lld\n", c);
    }
}
