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
    
    
int main()
{
    cin.sync_with_stdio ( 0 );
    cout.sync_with_stdio ( 0 );
    int T=1;
    cin>>T;
    assert(1 <= T && T <= 45);
    while(T--)
    {
        string str;
    cin>>str;
        assert(1 <= str.length() && str.length() <= 111);
        if(str.length() <= 1)
    {
        int a = (str[0] - '0');
        if(a% 8 == 0)
        cout<<"YES"<<endl;
        else
            cout<<"NO"<<endl;
            continue;
    }
    if(str.length() <= 2)
    {
        int a = 10*(str[0] - '0') + (str[1] - '0');
        int b = 10*(str[1] - '0') + (str[0] - '0');
        if(a% 8 == 0 || b% 8 == 0)
        cout<<"YES"<<endl;
        else
            cout<<"NO"<<endl;
        continue;
    }
    else
    {
        int l = str.length();
        int i,j,k;
        int temp=0;
        for(i=0 ; i< l ; i++)
        {
            for(j=0 ; j< l ; j++)
        {
            for(k=0 ; k< l ; k++)
            {
                if(i!=j && j!=k && k!=i)
            {
                int a = 100*(str[i] - '0') + 10*(str[j] - '0') + (str[k] - '0');
                if(a%8 == 0)
                {
                    temp=1;
                break;
                }
            }
            }
        }
        }
        if(temp==0)
            cout<<"NO"<<endl;
        else
            cout<<"YES"<<endl;
    }
    }
    return 0;
}
