#include <cstdio>
using namespace std;
typedef long long i64;
int etf(int n) {
    register int result = n, i, xcopy = n;
    for (i = 2; i * i <= xcopy; ++i) {
        if (n % i == 0) result -= result / i;
        while (n % i == 0) n /= i;
    }
    return (n > 1) ? result - result / n : result;
}
int invmod(int a, int b) {
    int t, nt, r, nr, q, tmp;
    if (b < 0) b = -b;
    if (a < 0) a = b - (-a % b);
    t = 0; nt = 1; r = b; nr = a % b;
    while (nr != 0) {
        q = r / nr;
        tmp = nt; nt = t - q * nt; t = tmp;
        tmp = nr; nr = r - q * nr; r = tmp;
    }
    if (r > 1) return -1; /* No inverse */
    if (t < 0) t += b;
    return t;
}
int solve(int a1, int n1, int a2, int n2, int mod) {
    i64 x = 1ll * a1 * n2 * invmod(n2, n1);
    if (x >= mod) x %= mod;
    i64 y = 1ll * a2 * n1 * invmod(n1, n2);
    if (y >= mod) y %= mod;
    x += y;
    if (x >= mod) x -= mod;
    return x;
}
int pow(const int base, const int exp, const int mod) {
    register int rx = 1 % mod, tmp = 1, e;
    i64 mul;
    for (e = 0; exp >> e; ++e) {
        mul = tmp * 1ll * ((e) ? tmp : base % mod);
        tmp = (mul >= mod) ? mul % mod : mul;
        if ((exp >> e) & 1) {
            mul = 1ll * rx * tmp;
            rx = (mul >= mod) ? mul % mod : mul;
        }
    }
    return rx;
}
int intlog(int n) {
    int rx = 0;
    while (1 << rx < n)
        ++rx;
    return rx;
}
int main() {
    int a, b;
    scanf("%d%d", &a, &b);
    //computing 2^(2^a) mod b
    int y = 0, etfx, fx, t;
    while (((b >> y) & 1) == 0) ++y;
    if (y == 0) {
        etfx = etf(b);
        fx = pow(2, a, etfx);
        printf("%d\n", pow(2, fx, b));
    } else {
        int a1, a2;
        t = b >> y;
        etfx = etf(t);
        fx = pow(2, a, etfx);
        a1 = pow(2, fx, t);
        if (a >= intlog(y)) a2 = 0;
        else a2 = 1 << a;
        printf("%d\n", solve(a1, t, a2, 1 << y, b));
    }
    return 0;
}
