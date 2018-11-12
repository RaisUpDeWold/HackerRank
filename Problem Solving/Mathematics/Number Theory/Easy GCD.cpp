#include <iostream>
#include <fstream>
#include <sstream>

#include <vector>
#include <set>
#include <bitset>
#include <map>
#include <deque>
#include <string>

#include <algorithm>
#include <numeric>

#include <cstdio>
#include <cassert>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <cmath>

#define pb push_back
#define pbk pop_back
#define mp make_pair
#define fs first
#define sc second
#define all(x) (x).begin(), (x).end()
#define foreach(i, a) for (__typeof((a).begin()) i = (a).begin(); i != (a).end(); ++i)
#define len(a) ((int) (a).size())

#ifdef CUTEBMAING
#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#else
#define eprintf(...) 42
#endif

using namespace std;

typedef long long int64;
typedef long double ld;
typedef unsigned long long lint;

const int inf = (1 << 30) - 1;
const int64 linf = (1ll << 62) - 1;

int gcd(int a, int b) {
    while (b) {
        int y = a % b;
        a = b, b = y;
    }
    return a;
}

int main() {
    int n, k; cin >> n >> k;
    int g = 0;
    for (int i = 0; i < n; i++) {
        int x; scanf("%d", &x);
        g = gcd(g, x);
    }
    int ans = 0;
    for (int i = 2; i * i <= g; i++) {
        if (g % i == 0) {
            ans = max(ans, k - k % i);
            ans = max(ans, k - k % (g / i));
        }
    }
    ans = max(ans, k - k % g);
    printf("%d\n", ans);
    return 0;
}
