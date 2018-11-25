#include<bits/stdc++.h>
 
using namespace std;
 
pair <int,int> A[1000005];
 
bool chk(int x)
{
    int p = (int)sqrt(x);
    if ( p*p == x || (p-1)*(p-1) == x || (p+1)*(p+1) == x ) return true;
    return false;
}
 
void pre()
{
    for ( int i = 1; i <= 1000; i++ ) {
        for ( int j = i; j <= 1000000; j += i ) {
            A[j].second++;
            if ( (i%2 == 0) && chk(i) ) A[j].first++;
            if ( (j/i > 1000) && (i != j/i) ) {
                A[j].second++;
                if ( ((j/i)%2 == 0) && chk(j/i) ) A[j].first++;
            }
        }
    }
    for ( int i = 1; i <= 1000000; i++ ) {
        A[i].second--;
        if ( (i%2 == 0) && chk(i) ) A[i].first--;
    }
    return;
}
 
int main()
{
    int t,x,val;
    pre();
    scanf("%d",&t);
    while ( t-- ) {
        scanf("%d",&x);
        if  (A[x].first == 0 ) {
            printf("0\n");
            continue;
        }
        val = __gcd(A[x].first,A[x].second);
        A[x].first /= val;
        A[x].second /= val;
        printf("%d/%d\n",A[x].first,A[x].second);
    }
    return 0;
}
