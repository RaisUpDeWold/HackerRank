#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int M = 1e5 + 10;

int n, p[M];
ll m;

void read() {
  cin >> n >> m;
  for (int i = 1; i <= n; ++i)
    cin >> p[i];
}

ll f(ll k) {
  ll cur = 0;
  while (k > 0) {
    if (cur >= n)
      return cur + k;
    cur = p[cur + 1];
    --k;
    cerr << cur << endl;
  }
  return cur;
}

int main() {
  read();
  cout << f(m) << endl;
  return 0;
}
