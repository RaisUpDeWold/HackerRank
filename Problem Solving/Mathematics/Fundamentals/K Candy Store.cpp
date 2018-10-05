#include<stdio.h>
#include<string.h>
#define MAXN     1003
#define MOD      1000000000

int dp[MAXN][MAXN];
int main()
{
    int i, j, idx, n, r, k, t, cnt;

    scanf("%d", &t);
    while(t--)
    {
        memset(dp, 0, sizeof(0));
        scanf("%d %d", &n, &k);

        for(idx = 1; idx <= n; idx++)
            for(cnt = 0; cnt <= k; cnt++)
            {
                if(!cnt) dp[cnt][idx] = 1;
                else dp[cnt][idx] = (dp[cnt][idx-1] + dp[cnt-1][idx]) % MOD;
            }

        printf("%d\n", dp[k][n]);
    }
    return 0;
}
