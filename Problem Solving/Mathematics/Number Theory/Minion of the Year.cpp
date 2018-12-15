#include <stdio.h>
#include <math.h>
#include <unordered_map>
#define ll long long
using namespace std;

ll min(ll a, ll b) { return a < b ? a : b; }

// fast exponentiation (b^e mod n)
ll ipow(ll b, ll e, ll n) {
    if (e == 0) return 1;
    if (e == 1) return b;
    if (e & 1) return ipow(b, e - 1, n) * b % n;
    return ipow(b * b % n, e >> 1, n);
}

ll fs[4111]; // factors
int fc;      // factor count

// check whether g is a generator mod p, assuming p-1's divisors are stored in (fs,fc)
int is_generator(ll g, ll p) {
    for (int fi = 0; fi < fc; fi++) {
        ll x = fs[fi];
        if (x < p-1) {
            if (ipow(g,x,p) == 1) {
                return 0;
            }
        }
    }
    return 1;
}


// find the lowest generator mod p
ll find_generator(ll p) {
    // store the factors of p-1 in (fs,fc)
    fc = 0;
    ll p1 = p-1;
    for (ll d = 1; d * d <= p1; d++) {
        if (p1 % d == 0) {
            fs[fc++] = d;
            if (d * d < p1) {
                fs[fc++] = p1 / d;
            }
        }
    }
    // find the answer iteratively
    ll g = 1;
    while (!is_generator(g,p)) g++;
    return g;
}

// for all a <= y <= b, find the minimum c*y + d*floor((e*y+f)/g)
/// runs in O(log g)
ll min_cdefg(ll a, ll b, ll c, ll d, ll e, ll f, ll g) {

    if (!(0 <= e && e < g)) {
        ll q = e / g, r = e % g;
        if (r < 0) r += g, q--;
        return min_cdefg(a,b,(c+d*q),d,r,f,g);
    }

    if (!(0 <= f && f < g)) {
        ll q = f / g, r = f % g;
        if (r < 0) r += g, q--;
        return min_cdefg(a,b,c,d,e,r,g) + d*q;
    }

    ll qa = (e*a+f)/g;
    ll qb = (e*b+f)/g;

    if (qa == qb) {
        return min(c*a, c*b) + d*qa;
    }

    ll ans;
    if (c > 0) {
        ans = min(c*a + d*qa, min_cdefg(qa+1,qb,d,c,g,e-f-1,e));
    } else {
        ans = min(c*b + d*qb, min_cdefg(qa,qb-1,d,c,g,g-f-1,e));
    }

    return ans;
}

// euclidean gcd
ll gcd(ll a, ll b) { 
    return b ? gcd(b, a % b) : a;
}

// extended euclidean gcd
ll x, y;
void egcd(ll a, ll b) {
    if (b == 0) {
        x = 1;
        y = 0;
    } else {
        egcd(b, a % b);
        ll t = x - (a / b) * y;
        x = y;
        y = t;
    }
}

// modular inverse of a mod n
ll inv(ll a, ll n) {
    egcd(a, n);
    return x;
}

// find the minimum (a*x+b*y) where c*x == d*y (mod m)
// runs in O(log m)
ll min_axby(ll a, ll b, ll c, ll d, ll m) {

    ll gc = gcd(c,m);
    ll gd = gcd(d,m);
    ll g = gcd(gc,gd);

    c /= gc;
    d /= gd;

    gc /= g;
    m /= gc * gd;
    gd /= g;

    b *= gc;
    a *= gd;
    d = d*inv(c,m) % m;

    ll ans;
    if (m == 1) {
        ans = a + b;
    } else {
        ans = min_cdefg(1,m-1,b+a*d,-a*m,d,0,m);
    }

    return ans;
}

unordered_map<ll,ll> table;
ll p, pw;
int u;

// find the discrete log of k, base g, mod p
// runs in O(p/u)
ll dlog(ll k) {
    ll bt = k % p;
    ll ee = 0;
    while (table.find(bt) == table.end()) {
        bt = bt * pw % p;
        ee += u;
    }
    return ee + table[bt];
}

int main() {
    int z;
    scanf("%d", &z);
    for (int cas = 1; cas <= z; cas++) {
        int n;
        scanf("%lld%d", &p, &n);

        // find generator mod p
        ll g = find_generator(p);

        // calculate u
        u = int(sqrt(n*p)*.35);
        if (u > p) u = p;

        // initialize the table from g^0 to g^(u-1)
        table.clear();
        pw = 1;
        for (int i = 0; i < u; i++) {
            table[pw] = i;
            pw = pw * g % p;
        }
        pw = inv(pw, p);
        if (pw < 0) pw += p;

        for (int i = 0; i < n; i++) {
            ll a, b, c, d;
            scanf("%lld%lld%lld%lld", &a, &b, &c, &d);
            c %= p;
            d %= p;

            // calculate answer
            ll ans = -1;
            if (!c == !d) {
                if (c) {
                    ans = min_axby(a, b, dlog(c), dlog(d), p-1);
                } else {
                    ans = a + b;
                }
            }

            // print answer
            if (~ans) {
                printf("%lld\n", ans);
            } else {
                printf("wala\n");
            }
        }
    }
}
