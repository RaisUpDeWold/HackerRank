#include <bits/stdc++.h>
using namespace std;

typedef long long lli;

#define pb push_back
#define SZ(a) ((int)a.size())
#define all(a) a.begin(), a.end()
#define build_unique(x) x.erase(unique(all(x)), x.end())

int n;
lli friendly, unfriendly;
vector<lli> gc;

lli gcd(lli a, lli b) {
  if (!b)
    return a;
  return gcd(b, a % b);
}

int main(void) {
  int i, j, k, kase = 0;
  scanf("%lld %lld", &n, &friendly);

  gc.clear();
  for (i = 0; i < n; i++) {
    scanf("%lld", &unfriendly);
    gc.pb(gcd(friendly, unfriendly));
  }

  sort(all(gc));
  build_unique(gc);

  int sz = sqrt(friendly);
  int sz2 = SZ(gc);
  int ans = 0;

  for (i = 1; i <= sz; i++) {
    if (friendly % i == 0) {
      for (j = 0; j < sz2; j++)
        if (gc[j] % i == 0)
          break;
      if (j == sz2)
        ans++;

      k = (friendly / i);
      if (k == i)
        continue;
      for (j = 0; j < sz2; j++)
        if (gc[j] % k == 0)
          break;
      if (j == sz2)
        ans++;
    }
  }

  printf("%d\n", ans);
  return 0;
}
