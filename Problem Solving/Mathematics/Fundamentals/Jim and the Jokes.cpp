#include <cstdio>
#include <cassert>
#include <map> 
using namespace std;
typedef long long ll;
int MAX_N = 849302837;
int N;
int C[40];

// returns a (in basis b) converted to decimal or -1 if a isn't a valid number in base b
int base(int a, int b){
  int r = 0, c = 1;
  while(a > 0){
    int x = a % 10;
    if(x >= b)
      return -1;
    a /= 10;
    r += x * c;
    c *= b;
  }
  return r;
}
int datesPerMonth[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

int main(){
  ll res = 0;
  int m, d, x;
  scanf("%d", &N);
  assert(1 <= N && N <= MAX_N);
  for(int i = 0; i < N; i++){
    scanf("%d%d", &m, &d);
    assert( 1 <= m && m <= 12);
    assert( 1 <= d && d <= datesPerMonth[m]);

    x = base(d, m);
    if(x != -1){
      res += C[x];
      C[x] += 1;
    }
  }
  printf("%lld\n", res);
  return 0;
}
