#include<iostream>
#include<vector>
    
using namespace std;
    
#define MOD 99991
    
long long int fact[400001];
    
long long int pwr(long long int a , long long int b) {
    if(b == 0)
        return 1;
    if(b == 1)
        return a;
    if(b % 2 == 0) {
        long long int temp = pwr(a, b / 2);
        return (temp * temp) % MOD;
    } else {
        long long int temp = pwr(a, b / 2);
        temp = (temp * temp) % MOD;
        return (temp * a) % MOD;
    }
}

long long SmallC(long long int N, long long int R) {
    long long int a = fact[N];
    long long int b = fact[R];
    long long int c = fact[N - R];
    a = (a * pwr(b, MOD - 2)) % MOD;
    a = (a * pwr(c, MOD - 2)) % MOD;
    return a;
}

long long Lucas(long long int n, long long int m) {
    if (n == 0 && m == 0)
        return 1;
    long long int ni = n % MOD;
    long long int mi = m % MOD;
    if (mi > ni)
        return 0;
    return Lucas(n / MOD, m / MOD) * SmallC(ni, mi);
}

int main() {
    fact[0] = 1;
    for(long long int i = 1; i <= 400000; i ++)
        fact[i] = (fact[i - 1] * i) % 99991;
    long long int n, T;
    cin >> T;
    while (T --) {
        cin >> n;
        long long int outp = Lucas(3 * n, n);
        outp = outp + 2 * 99991 - 2 * Lucas(3 * n, n - 1) + Lucas(3 * n, n - 2);
        cout << (99991 + outp % 99991) % 99991 << endl;
    }
    return 0;
}
