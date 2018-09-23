#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

typedef long long ll;
const int N = 2*1024*1024;
const ll MOD = 1000*1000*1000+7;

ll fact[N];

ll modPower(ll x, ll n)
{
    if(n == 0)
        return 1;
    if(n == 1)
        return x % MOD;

    ll res = modPower(x, n/2);
    res = res * res % MOD;

    if(n % 2 == 1)
        res = res * x % MOD;

    return res;
}

ll inv(ll x)
{
   return modPower(x, MOD-2);
}

ll combination(ll n, ll k)
{
    if(k == 0 || k == n)
        return 1;

    if(k > n || n <= 0)
        return 0;

    return fact[n] * inv(fact[k]) % MOD * inv(fact[n-k]) % MOD;
}

int main() {

    fact[0] = 1;
    for(int i = 1; i < N; i ++) {
        fact[i] = fact[i-1] * i % MOD;
    }

    int test;
    int n, k;
    cin >> test;
    while (test --) {
        cin >> n >> k;
        if(n == 1 || k == 1) {
            cout << 0 << endl;
            continue;
        }

        ll res = 0;
        for(int i = 1; i <= k; i ++) {
            res = (res + combination(n-k-(i-1)+i, i) * combination(k-i*2+i-1, i-1) % MOD) % MOD;
        }
        cout << res << endl;
    }

    return 0;
}
