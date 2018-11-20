#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <string>
#include <memory.h>
#include <sstream>
#include <complex>
#include <cassert>
    
#define REP(i,n) for(int i = 0, _n = (n); i < _n; i++)
#define REPD(i,n) for(int i = (n) - 1; i >= 0; i--)
#define FOR(i,a,b) for (int i = (a), _b = (b); i <= _b; i++)
#define FORD(i,a,b) for (int i = (a), _b = (b); i >= _b; i--)
#define FORN(i,a,b) for(int i=a;i<b;i++)
#define FOREACH(it,c) for (__typeof((c).begin()) it=(c).begin();it!=(c).end();it++)
#define RESET(c,x) memset (c, x, sizeof (c))
    
#define PI acos(-1)
#define sqr(x) ((x) * (x))
#define PB push_back
#define MP make_pair
#define F first
#define S second
#define Aint(c) (c).begin(), (c).end()
#define SIZE(c) (c).size()
    
#define DEBUG(x) { cerr << #x << " = " << x << endl; }
#define PR(a,n) {cerr<<#a<<" = "; FOR(_,1,n) cerr << a[_] << ' '; cerr <<endl;}
#define PR0(a,n) {cerr<<#a<<" = ";REP(_,n) cerr << a[_] << ' '; cerr << endl;}
#define LL long long
    
#define maxn 24
    
using namespace std;
    
int Gauss(int n, int a[][maxn * maxn], int b[]) {
    for (int i = 0; i < n; i++) {
        int row = -1;
        for (int j = i; j < n; j++)
            if (a[j][i]) {
                row = j;
                break;
            }
    
        if (row == -1) continue;
    
        if (!a[i][i])
            for (int j = 0; j <= n; j++)
                a[i][j] ^= a[row][j];
    
        for (int k = i; k < n; k++)
        if (k != i && a[k][i] == 1) {
            for (int j = 0; j <= n; j++)
                a[k][j] ^= a[i][j];
        }
    }
    
    for (int i = 0; i < n; i++)
        if (a[i][n]) {
            int ok = 0;
            for (int j = 0; j < n; j++)
                if (a[i][j]) {
                    ok = 1;
                    break;
                }
            if (!ok) return 0;
        }
    
    for (int i = n - 1; i >= 0; i--) {
       if (a[i][i] == 0 && a[i][n] == 1) return 0;
        if (a[i][i] == 0) b[i] = 0;
        else b[i] = a[i][n];
    
        if (b[i])
        for (int j = i - 1; j >= 0; j--)
            if (a[j][i] == 1) a[j][n] ^= 1;
    }
    
    return 1;
}
    
int n, d, g[maxn][maxn], a[maxn * maxn][maxn * maxn], root[maxn * maxn];
    
int main() {
    cin >> n >> d;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> g[i][j];
    
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++) {
            int row = i * n + j;
    
            a[row][n * n] = g[i][j];
    
            for (int x = 0; x < n; x++)
                for (int y = 0; y < n; y++)
                    if (abs(x - i) + abs(y - j) <= d) {
                       // cerr << x * n + y << endl;
                        a[row][x * n + y] = 1;
                    }
        }
    
    int res = Gauss(n * n, a, root);
    
    if (!res) cout << "Impossible" << endl;
    else {
        cout << "Possible" << endl;
        int cnt = 0;
        for (int i = 0; i < n * n; i++)
            cnt += root[i];
    
        cout << cnt << endl;
    
        for (int i = 0; i < n * n; i++)
            if (root[i]) cout << i / n << " " << i % n << endl;
    }
    
    return 0;
}
