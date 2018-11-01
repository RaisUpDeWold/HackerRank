#include<stdio.h>
#include<algorithm>
#include<assert.h>
using namespace std;
#define upper 1000000000
typedef long long int ll;
int pow(ll a,int b)
{
ll ans=1;
while(b){
    if(b&1){
        ans = ans*a;
        assert(ans<=upper);
    }
    a=a*a;
    b>>=1;
}
return ans;
}
int main()
{
int test,x,a,b,req,v1,v2,v3;
scanf("%d",&test);
while(test--){
    scanf("%d%d%d",&a,&b,&x);
    assert(a>=1 && a<=1000000000);
    assert(x>=1 && x<=1000000000);
    if(b<0){
        if(a==1 && x==1)    printf("1\n");
        else    printf("0\n");
        continue;
    }
    req= pow(a,b);
    assert(req<=1000000000);
    v1=req/x;
    v2 = x*(v1);
    v3= x*(v1+1);
    printf("%d\n",((req-v2)<=(v3-req))?v2:v3);
}
return 0;
}
