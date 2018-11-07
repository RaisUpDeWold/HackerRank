#define _USE_MATH_DEFINES
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <iostream>
#include <sstream>
#include <vector>
#include <algorithm>
#include <set>
#include <queue>
#include <map>
#include <string>
#include <unordered_map>
#include <unordered_set>
#define N 10000001
using namespace std;

int p[N];
unordered_map<int,int> mp;
int i, j, T, n, x, m, ans, k, l;
int a[51][10];
int sumN;

int main()
{
    for(i = 2; i * i < N; i ++)
        if(!p[i])
        {
            p[i] = i;
            for(j = i * i; j < N; j += i)
                p[j] = i;
        }
    for(; i < N; i ++)
        if(!p[i])
            p[i] = i;
    scanf("%d", &T);
    if(T < 1 || T > 100000)
        throw;
    while(T --)
    {
        scanf("%d", &n);
        if(n < 1 || n > 50)
            throw;
        sumN += n;
        mp.clear();
        m = 0;
        for(i = 0; i < n; i ++)
        {
            scanf("%d", &x);
            if(x < 1 || x > 10000000)
                throw;
            memset(a[i], 0, sizeof(a[i]));
            while(p[x])
            {
                if(mp.find(p[x]) == mp.end())
                    mp[p[x]] = m ++;
                j = mp[p[x]];
                x /= p[x];
                a[i][j / 32] ^= 1 << j % 32;
            }
        }
        m = (m + 31) / 32;
        ans = n;
        for (i = 0; i < n; i ++)
        {
            for (j = 0; j < m; j ++)
                if(a[i][j])
                    break;
            if (j == m)
            {
                ans --;
                continue;
            }
            x = a[i][j] & a[i][j] - 1 ^ a[i][j];
            for (k = i + 1; k < n; k ++)
                if (a[k][j] & x)
                    for (l = 0; l < m; l ++)
                        a[k][l] ^= a[i][l];
        }
        printf("%lld\n", 1LL<<ans);
    }
    if(sumN > 100000)
        throw;
    return 0;
}
