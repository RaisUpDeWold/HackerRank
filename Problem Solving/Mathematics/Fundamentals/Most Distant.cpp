#include <bits/stdc++.h>

using namespace std;

#define dbgs(x) cerr << (#x) << " --> " << (x) << ' '
#define dbg(x) cerr << (#x) << " --> " << (x) << endl

#define foreach(i,x) for(type(x)i=x.begin();i!=x.end();i++)
#define FOR(ii,aa,bb) for(int ii=aa;ii<=bb;ii++)
#define ROF(ii,aa,bb) for(int ii=aa;ii>=bb;ii--)

#define type(x) __typeof(x.begin())

#define orta (bas + son >> 1)
#define sag (k + k + 1)
#define sol (k + k)

#define pb push_back
#define mp make_pair

#define nd second
#define st first

#define endl '\n'
#define pii pair< ll , ll >
typedef long long ll;

const long long linf = 1e18+5;
const int mod = (int) 1e9 + 7;
const int logN = 18;
const int inf = 1000000009;
const int N = 1e6+5;

#define K(x) ((ll)(x)*(x))

ll n, x, y, max_x, max_y, min_x, min_y, ans;

pair< ll , ll > a[5];

int main() {

    scanf("%lld", &n);
    a[1] = mp(0, -inf);
    a[2] = mp(0,  inf);
    a[3] = mp(-inf, 0);
    a[4] = mp( inf, 0);

    FOR(i, 1, n) {
        scanf("%lld %lld", &x, &y);
        pii temp;
        temp = mp(x, y);
        if(x == 0) {
            a[1] = max(a[1], temp);
            a[2] = min(a[2], temp);
        }
        if(y == 0) {
            a[3] = max(a[3], temp);
            a[4] = min(a[4], temp);
        }
    }

   FOR(i, 1, 4)
        if(abs(a[i].st) != inf && abs(a[i].nd) != inf)
            FOR(j, i+1, 4)
                if(abs(a[j].st) != inf && abs(a[j].nd) != inf)
                    ans = max(ans, K(a[i].st-a[j].st)+K(a[i].nd-a[j].nd));

    printf("%.12lf\n", sqrt(abs(ans)));

    return 0;
}
