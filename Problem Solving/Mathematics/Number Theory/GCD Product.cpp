#include <cstdio>
#include <algorithm>
using namespace std;

#define maxn 15000000 + 5
#define mod 1000000007
#define tm Tm

int n, m, i, j, p[maxn], dp[maxn], sf[maxn], sfn, g, tn, tm, ret, pref[maxn], l, c, p1, p2, r, carry;
long long sfm[maxn], t;

int pw (int x, long long p) {
    if (!p) return 1;
    if (p == 1) return x;
    int q = pw(x, p >> 1);
    q = (1LL * q * q) % mod;
    if (p & 1) q = (1LL * q * x) % mod;
    return q;
}

int main (int argc, char * const argv[]) {
    scanf("%d %d", &n, &m);
    if (n < m) swap(n, m);
    for(i = 2; i <= n; i++) if (p[i] == 0) {
        j = i;
        while (j <= n) {
            if (!p[j]) p[j] = i;
            j += i;
        }
    }
    for(i = 2; i <= n; i++) {
        if (i == p[i]) dp[i] = -1; else
            if (p[(i / p[i])] == p[i]) dp[i] = 0; else dp[i] = -1 * dp[i / p[i]];
        pref[i] = pref[i - 1] + dp[i];
    }
    for(i = 1; i <= n; i++) if (dp[i] != 0) {
        sf[++sfn] = i;
        sfm[sfn] = dp[i];
    }
    sf[sfn + 1] = m + 1;
    ret = 1;
    carry = 1, t = 1, tn = tm = -1;
    for(g = 2; g <= m; g++) {
        if (n / g != tn || m / g != tm) {
            ret = (ret * 1LL * pw(carry, t)) % mod;
            carry = 1LL;
        } else {
            carry = (carry * 1LL * g) % mod;
            continue;
        }
        tn = n / g;
        tm = m / g;
        t = 1LL * tn * tm;
        if (g <= 600000) {
            l = 1;
            while (l <= tm) {
                ++c;
                r = min(min(tn / (p1 = tn / l), tm / (p2 = tm / l)), tm);
                t += p1 * 1LL * p2 * (pref[r] - pref[l - 1]);
                l = r + 1;
            }
        } else for(i = 1; sf[i] <= tm; i++) t += sfm[i] * (tn / sf[i]) * (tm / sf[i]);
        carry = (1LL * carry * g) % mod;
    }
    ret = (ret * 1LL * pw(carry, t)) % mod;
    printf("%d\n", ret);
    return 0;
}
