#include <bits/stdc++.h>
using namespace std;
#define sz(x) ((int) (x).size())
#define forn(i,n) for (int i = 0; i < int(n); ++i)
typedef long long ll;
typedef long long i64;
typedef long double ld;
const int inf = int(1e9) + int(1e5);
const ll infl = ll(2e18) + ll(1e10);

const int maxn = 100100;
ll a[maxn];
ll d[2][maxn];

ll gcd(ll a, ll b) {
    while (a && b)
        if (a >= b)
            a %= b;
        else
            b %= a;
    return a + b;
}

int main() {
    int n;
    cin >> n;
    forn (i, n)
        cin >> a[i];
    if (n == 1) {
        cout << a[0] + 1 << '\n';
        return 0;
    }
    forn (q, 2) {
        forn (i, n)
            d[q][i + 1] = gcd(d[q][i], a[i]);
        reverse(a, a + n);
    }
    forn (i, n) {
        ll x = gcd(d[0][i], d[1][n - i - 1]);
        if (a[i] % x != 0) {
            cout << x << '\n';
            return 0;
        }
    }
    assert(false);
}
