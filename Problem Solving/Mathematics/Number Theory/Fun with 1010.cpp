#include <stdio.h>
#define ll long long
#define mod 2000003
#define half (mod + 1 >> 1)

ll fac[mod];
ll ifc[mod];

ll ipow(ll b, ll e) {
    if (e == 0) return 1;
    if (e == 1) return b;
    if (e & 1) return ipow(b, e - 1) * b % mod;
    return ipow(b * b % mod, e >> 1);
}

ll C(ll n, ll r) {
    if (r < 0 or r > n) {
        return 0;
    }
    if (n >= mod) {
        return C(n/mod, r/mod) * C(n%mod, r%mod) % mod;
    }
    return fac[n] * ifc[n-r] % mod * ifc[r] % mod;
}

ll f(ll n, ll m) {
    ll h = n - 1;
    ll cb = C(2*h,h);
    ll pw = ipow(2,h);
    ll pw3 = (pw-1)*(pw-1)*(pw-1)%mod;
    return ((m+1)*pw3 + h*half%mod*(3*cb*(1-pw*half%mod)%mod - pw3 - 1)) % mod;
}


int main() {
    fac[0] = fac[1] = ifc[0] = ifc[1] = 1;
    for (int i = 2; i < mod; i++) {
        ifc[i] = (mod - mod/i) * ifc[mod%i] % mod;
    }

    for (int i = 2; i < mod; i++) {
        fac[i] = fac[i-1] *     i  % mod;
        ifc[i] = ifc[i-1] * ifc[i] % mod;
    }

    int z;
    scanf("%d", &z);
    while (z--) {
        ll n, m;
        scanf("%lld%lld", &n, &m);
        ll ans = f(n, m);
        if (ans < 0) ans += mod;
        printf("%lld\n", ans);
    }
}
