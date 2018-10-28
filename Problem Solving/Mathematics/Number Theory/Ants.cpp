#include <bits/stdc++.h>
using namespace std;

typedef long long lli;

#define _rep(i, a, b, x) for (i = (a); i <= (b); i += x)
#define rep(i, n) _rep(i, 0, n - 1, 1)

int n;
int pos[1007];
int main() {
  int i;
  cin>>n;
  rep(i, n) cin>>pos[i];

  // we consider half of the ants to be in same direction
  // and the other half in opposite direction
  // in one full cycle, one ant will face every other ants in it's opposite
  // direction twice
  //(1000000000L/(1000*10)) is the number of cycle in 1000000000 sec
  lli ans = (n - n / 2) * (n / 2) * 2 * (1000000000L / (1000 * 10));

  // After all the full cycles, the ants positions are just as it were in the
  // beginning
  // We now take care of the next 6 seconds.
  // Only two ants facing each other and in 1 unit distance can meet each other
  // in 6 seconds
  // So we check for consecutive ant positions
  sort(pos, pos + n);

  int cnt = 0;
  rep(i, n) {
    if ((pos[i] + 1) == pos[i + 1])
      cnt++;
    else {
      // cnt+1 is the consecutive position length
      // two consecutive ants in opposite direction can meet once.
      ans += ((cnt + 1) / 2);
      cnt = 0;
    }
  }
  //'ans' is the total number of meet ups of two ants
  // 2 'hi' will occur in each meet up.
  printf("%lld\n", ans * 2LL);
  return 0;
}
