#include <stdio.h>
#include <stdlib.h>
#define mod 1000000007
#define min(a,b) ((a)<(b)?(a):(b))
#define LIM 1000
#define ull unsigned long long
#define _9_10 300000003 // (9/10'ths mod 10^9+7)

ull fac[LIM+1];
ull ifc[LIM+1];
ull **F[11];

int main() {
    // precalculate factorials and inverse factorials
    fac[0] = ifc[0] = fac[1] = ifc[1] = 1;
    for (int i = 2; i <= LIM; i++) { // put the inverses in ifc
        ifc[i] = (mod - mod/i) * ifc[mod%i] % mod;
    }
    for (int i = 2; i <= LIM; i++) { // precalculate fac and ifc
        fac[i] = fac[i-1] *     i  % mod;
        ifc[i] = ifc[i-1] * ifc[i] % mod;
    }

    // precalculate F[d][n][k] = f_d(n,k)
    // around 10^2/2 * 600^2/2 < 10000000 operations
    for (int d = 0; d <= 10; d++) {
        F[d] = (ull**)malloc((LIM+1)*sizeof(ull*));
        for (int n = 0; n <= LIM; n++) {
            F[d][n] = (ull*)calloc(n+1, sizeof(ull));
            for (int k = 0; k <= n; k++) {
                if (n == 0) {
                    F[d][n][k] = 1;
                } else if (k == 0 or d == 0) {
                    F[d][n][k] = 0;
                } else {
                    ull s = 0;
                    ull pw = 1;
                    int nn = n;
                    int nk = k-1;
                    for (int e = 0; e <= d; e++) {
                        if (e*k > n) break;
                        s += fac[d] * ifc[e] % mod * ifc[d-e] % mod * fac[n] % mod * ifc[nn] % mod * pw % mod * F[d-e][nn][min(nn,nk)];
                        pw = pw * ifc[k] % mod;
                        nn -= k;
                    }
                    F[d][n][k] = s % mod;
                }
            }
        }
    }



    ull **f = F[10];
    int z;
    scanf("%d", &z);
    for (int cas = 1; cas <= z; cas++) {
        int n, k;
        scanf("%d%d", &n, &k);
        ull ans = f[n][min(n, k)] * _9_10 % mod; // 1/10'ths of the numbers start with zero
        printf("%llu\n", ans);
    }
}
