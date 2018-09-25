#include <iostream>
using namespace std;
    
typedef long long LL;
    
const int MOD = 1000000007;
    
// L and R should be of size 8
int calc(int *L, int *R) {
    // we extend L and R for convenience
    for (int i = 0; i < 4; ++i) {
        L[4 + i] = L[i];
            R[4 + i] = R[i];
    }
    // init ans by N()
    int ans = 1;
    for (int i = 0; i < 4; ++i) {
        ans = LL(ans) * (R[i] - L[i] + 1) % MOD;
    }
    for (int j = 0; j < 4; ++j) {
        int L1 = max(L[j], L[j+1]);
        int R1 = min(R[j], R[j+1]);
        if (L1 > R1) {
            continue;
        }
        // cur is N(x[j]=x[j+1])
        int cur = LL(R1 - L1 + 1) * (R[j+2] - L[j+2] + 1) % MOD * (R[j+3] - L[j+3] + 1) % MOD;
        // we subtract cur from the answer
        ans = (ans + MOD - cur) % MOD;
    
        // L1 = max(L[j], L[j+1], L[j+2])
        // R1 = min(R[j], R[j+1], R[j+2])
        L1 = max(L1, L[j+2]);
        R1 = min(R1, R[j+2]);
        if (L1 <= R1) {
            // we add N(x[j]=x[j+1]=x[j+2]) to the answer
            ans = (ans + LL(R1-L1+1) * (R[j+3]-L[j+3]+1)) % MOD;
        }
    }
    for (int j = 0; j < 2; ++j) {
        int L1 = max(L[j], L[j+1]);
        int R1 = min(R[j], R[j+1]);
        int L2 = max(L[j+2], L[j+3]);
        int R2 = min(R[j+2], R[j+3]);
        if (L1 <= R1 && L2 <= R2) {
            // we add N(x[j]=x[j+1], x[j+2]=x[j+3]) to the answer
            ans = (ans + LL(R1 - L1 + 1) * (R2 - L2 + 1)) % MOD;
        }
    }
    int maxL = L[0], minR = R[0];
    for (int j = 1; j < 4; ++j) {
        maxL = max(maxL, L[j]);
        minR = min(minR, R[j]);
    }
    if(maxL <= minR) {
        // we subtract 3 * N(x[j]=x[j+1]=x[j+2]=x[j+3]) from the answer
        ans = (ans - 3LL * (minR - maxL + 1)) % MOD;
        if (ans < 0) {
            ans += MOD;
        }
    }
    return ans;
}
    
int main() {
    //freopen("input/input00.txt","r",stdin);
    int T;
    cin >> T;
    for (int t = 0; t < T; ++t) {
        int L[8], R[8];
        for (int i = 0; i < 4; ++i) {
            cin >> L[i] >> R[i];
        }
        int ans = calc(L, R);
        cout << ans << endl;
    }
    return 0;
}
