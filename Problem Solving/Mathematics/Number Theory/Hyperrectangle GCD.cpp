#include <cstdio>
#include <vector>
#include <cstring>
#include <algorithm>
    
using namespace std;
    
const int MOD = (int)1e9 + 7;
    
int a[510];
int cnt[100100];
int inv[100100];
vector <int> ev[100100];
    
void add(int &a, int b) {
    a += b;
    if (a >= MOD) a -= MOD;
}
    
int binpow(int a, int n) {
    if (n == 0) return 1;
    if (n % 2 == 1) return (long long)a * binpow(a, n - 1) % MOD;
    int t = binpow(a, n / 2);
    return (long long)t * t % MOD;
}
    
int clever(int* v, int n) {
    int mx = *max_element(v, v + n);
    memset(cnt, 0, 4 * (mx + 1));
    for (int i = 1; i <= mx; i++) ev[i].clear();
    for (int i = 0; i < n; i++) {
        int bound = 1, cur = v[i];
        while (cur > 0) {
            int L = bound, R = v[i] + 1;
            while (L + 1 < R) {
                int M = (L + R) / 2;
                if (v[i] / M < cur) {
                    R = M;
                } else {
                    L = M;
                }
            }
            ev[L].push_back(v[i]);
            bound = L + 1;
            cur = v[i] / (L + 1);
        }
    }
    long long cur = 1;
    for (int i = 0; i < n; i++) cur *= v[i], cur %= MOD;
    for (int i = 1; i <= mx; i++) {
        if (cur == 0) break;
        cnt[i] = (int)cur;
        if (i == mx) break;
        for (int j = 0; j < ev[i].size(); j++) {
            cur *= inv[ev[i][j] / i];
            cur %= MOD;
            cur *= (ev[i][j] / (i + 1));
            cur %= MOD;
        }
    }
    for (int i = mx; i >= 1; i--) {
        for (int j = 2 * i; j <= mx; j += i) {
            cnt[i] -= cnt[j];
            if (cnt[i] < 0) {
                cnt[i] += MOD;
            }
        }
    }
    int res = 0;
    for (int i = 0; i <= mx; i++) add(res, (long long)cnt[i] * i % MOD);
    return res;
}
    
int main() {
    for (int i = 1; i < 100100; i++) {
        inv[i] = binpow(i, MOD - 2);
    }
    int t;
    scanf("%d", &t);
    while (t--) {
        int n;
        scanf("%d", &n);
        for (int i = 0; i < n; i++) scanf("%d", &a[i]);
        printf("%d\n", clever(a, n));
    }
    return 0;
}
