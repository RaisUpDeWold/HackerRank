#include <bits/stdc++.h>;

using namespace std;

#define sz(x) ((int) (x).size())
#define forn(i,n) for (int i = 0; i < int(n); ++i)
#define forab(i,a,b) for (int i = int(a); i < int(b); ++i)

typedef long long ll;
typedef long double ld;

const int INF = 1000001000;
const ll INFL = 2000000000000001000;

int mod;

void gen(int &a, int &b)
{
    int res = a + b;
    if (res >= mod)
        res -= mod;
    a = b;
    b = res;
}

const int maxn = 10000000;
const int htmod = 1 << 26;

int ht[htmod + 1000000];
int sz;

void put(int x)
{
    int id = x & (htmod - 1);
    while (ht[id] != -1 && ht[id] != x)
        ++id;
    if (ht[id] == -1)
    {
        ht[id] = x;
        ++sz;
    }
}

int main()
{
    memset(ht, 255, sizeof(ht));
    int a = 0, b;
    int n;
    cin >> b >> mod >> n;
    b %= mod;
    ll mult = b;
    int bd = 4 * n;
    forab (i, 2, bd)
    {
        gen(a, b);
        if (i % 2 && i > 6)
            put((b * mult) % mod);
    }
    cout << sz << '\n';
    return 0;
}
