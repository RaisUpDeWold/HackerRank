#include<map>
#include<set>
#include<ctime>
#include<cmath>
#include<queue>
#include<stack>
#include<bitset>
#include<vector>
#include<cstdio>
#include<string>
#include<cassert>
#include<cstring>
#include<numeric>
#include<sstream>
#include<iterator>
#include<iostream>
#include<algorithm>

using namespace std;
typedef unsigned long long LL;

#define MOD7 1000000007
#define MOD9 1000000009

#define pb push_back
#define mp make_pair


#define MM(a,x) memset(a, x, sizeof(a))
#define P(x) cout<<#x<<" = "<<x<<endl;
#define P2(x,y) cout<<#x<<" = "<<x<<", "<<#y<<" = "<<y<<endl;
#define PV(a,n) for(int i=0;i<n;i++) cout<<#a<<"[" << i <<"] = "<<a[i]<<endl;
#define TM(a,b) cout<<#a<<"->"<<#b<<": "<<1.*(b-a)/CLOCKS_PER_SEC<<"s\n";

#define all(X) (X).begin(), (X).end ()
#define for_each(it, X) for (__typeof((X).begin()) it = (X).begin(); it != (X).end(); it++)

int N,K;

void reverse(int i) // index of K after rotaing [i,N]
{
        K=K-i;
        K = N-i-1-K;
        K = K+i;
        return;
}
int main()
{
    cin.sync_with_stdio ( 0 );
    cout.sync_with_stdio ( 0 );
    int T=1,i;
    cin>>T;
    while(T--)
    {
        cin>>N>>K;
        for(i=0; i< N ; i++)
        {
            if(K < i) // Now rotation will make no affect 
                break;
            else
                reverse(i);
        }
        cout<<K<<endl;
    }
    return 0;
}
