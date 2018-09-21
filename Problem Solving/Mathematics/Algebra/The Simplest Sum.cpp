#include <iostream>
#include <cassert>
#include <cmath>

using namespace std;

const long long nmx = 1e18;
const long long mod = 1e9 + 7;

int b[100005];
long long f[100005][60];
long long s[100005][60];

int bucket(long long n, int k) {
    long long b = 0;
    
    for (int i = 1; i < 60; i++) {
        b = pow(k, i - 1) + b;
        
        if (n >= b and n <= k * b) {
            return i;
        }
    }
    
    return 0;
}

long long start(int b, int k) {
    long long n = 0;
    
    for (int i = 1; i <= b; i++) {
        n = pow(k, i - 1) + n;
    }
    
    return n;
}

void pre() {
    for (int i = 2; i < 100005; i++) {
        b[i] = floor(log(nmx) / log(i));
    }
    
    for (int k = 2; k < 100005; k++) {
        f[k][1] = 1;
        s[k][1] = 1;
        
        for (int i = 2; i <= b[k]; i++) {
            f[k][i] += f[k][i - 1] * k;
            f[k][i] %= mod;
            f[k][i] += i;
            f[k][i] %= mod;
            
            s[k][i] = f[k][i];
            s[k][i] *= (((k - 1) * start(i, k)) % mod + 1) % mod;
            s[k][i] %= mod;
        }
        
        for (int i = 1; i <= b[k]; i++) {
            s[k][i] += s[k][i - 1];
            s[k][i] %= mod;
        }
    }
}

int main()
{
    pre();
    
    int q;
    cin >> q;
    assert(q >= 1 and q <= 1e5);
    
    for (int i = 1; i <= q; i++) {
        int k;
        long long l, r;

        cin >> k >> l >> r;
        assert(q >= 1 and q <= 1e5);
        assert(l >= 1 and l <= nmx);
        assert(r >= l and r <= nmx);
        
        int bl = bucket(l, k);
        int br = bucket(r, k);
        
        if (bl == br) {
            long long d = r - l + 1;
            long long v = f[k][bl];
            
            long long sum = (d * v) % mod;
            
            cout << sum;
        } else {
            long long ble = k * start(bl, k);
            long long brs = start(br, k);
            
            long long dl = ble - l + 1;
            long long dr = r - brs + 1;
            
            long long vl = f[k][bl];
            long long vr = f[k][br];
            
            long long sl = (dl * vl) % mod;
            long long sr = (dr * vr) % mod;
            
            long long sum = (sl + sr) % mod;
            
            br--;
            
            if (br > bl) {
                long long sm = (s[k][br] - s[k][bl] + mod) % mod;
                
                sum += sm;
                sum %= mod;
            }
            
            cout << sum;
        }
        
        if (i != q) {
            cout << endl;
        }
    }
    
    return 0;
}
