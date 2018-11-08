#include<stdio.h>
#include<assert.h>
#include<algorithm>
using namespace std;
#define MaxN 200001
typedef long long int ll;
ll A[MaxN],x;
ll SUPER = (ll)100000000*(ll)100000000;
int bs11(int low,int high,int k,int arr[])//returns the index of that number which is equal to or just larger than it
{
    int mid=(low+high)/2;
    if(arr[low]>k ||  arr[low]==k)
        return arr[low];
    else if(arr[mid]==k)
        return arr[mid];
    else if((arr[mid]<k) && arr[mid+1]>k)
        return arr[mid+1];
    else if(arr[mid]<k)
        return bs11(mid+1,high,k,arr);
    else
        return bs11(low,mid-1,k,arr);
}
int check(int a,int b)
{
    ll answer = 1,who,mul;
    for(int i=b;i>=a;i--){
        mul=A[i];
        who=answer;
        answer =1;
        while(who){
            if(who&1){
                answer = answer * mul;
                if(answer>60)    return -1;
                who--;
            }
            else{
                if(mul>60)    return -1;
                mul=mul*mul;
                if(mul>60)    return -1;
                who>>=1;
            }
        }
    }
    return answer;
}
ll mulmod(ll a, ll b,ll x)
{
    //printf("%lld is s b\n",b);
    ll ans =0;
    while(b){
        if(b&1){
            ans = ans+ a;
            if(ans>=x)    ans -= x;
            b--;
        }
        else{
            a=a+a;
            if(a>=x)    a-=x;
            b>>=1;
        }
    }
    return ans;
}
ll powmod(ll a,int b,ll x)    //a^b mod x
{
    if( a>=x )     a%=x;
    //printf("%d is b %lld\n",b,a);
    ll answer = 1;
    while(b){
        if(b&1)    answer=mulmod(answer,a,x);
        a=mulmod(a,a,x);
        b>>=1;
    }
    return answer%x;
}
int main()
{
    int search0[MaxN],search1[MaxN];
    int N,a,b,counter0=1,counter1=1,ind,val,Q;
    search0[0]=-1;
    search1[0]=-1;
    ll answer ,last=1;
    scanf("%d",&N);
    assert(N<=200000);
    for(int i=1;i<=N;i++){
        scanf("%lld",&A[i]);
        if(last == 0 && A[i]==0)    assert(0);
        assert(A[i]>=0 && A[i]<=SUPER);
        last = A[i];
        if(A[i]==0){
            search0[counter0]=i;
            counter0++;
        }
        if(A[i]==1){
            search1[counter1]=i;
            counter1++;
        }
    }
    search0[counter0]=MaxN+1;
    search1[counter1]=MaxN+1;
    scanf("%d",&Q);
    assert(Q<=300000);
    for(int query=1;query<=Q;query++){
        scanf("%d%d%lld",&a,&b,&x);
        assert(a>=1 && a<=N);
        assert(b>=1 && b<=N);
        assert(a<=b);
        assert(x>=1 && x<=SUPER);
        //printf("s0 %d %d\n",a,b);
        if(a==b){
            answer = A[a]%x;
        }
        else{
            ind = min ( b, bs11(0,counter0,a+1,search0));
            val = check(a+1,min(ind,bs11(0,counter1,a+1,search1)));
            //printf("s1\n");
            if(val!=-1)    answer = powmod(A[a],val,x);    
            else        answer = powmod(A[a],60,x);
            //printf("s2\n");
        }
        if(answer == 0 ) printf("Yes\n");
        else    printf("No\n");
    }
}
