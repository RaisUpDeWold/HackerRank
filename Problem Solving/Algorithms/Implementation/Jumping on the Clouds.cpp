#include <bits/stdc++.h>
using namespace std;

const int inf = 555;
int A[111], dp[111];

int main() {
    int n; cin >> n;

    for(int i = 1; i <= n; i ++) {
        cin >> A[i];
    }
    for(int i = 2; i <= n; i++) {
        if(A[i] == 0) dp[i] = min(dp[i - 1], dp[i - 2]) + 1;
        else dp[i] = inf;
    }
    cout << dp[n] << "\n";
    return 0;
}
