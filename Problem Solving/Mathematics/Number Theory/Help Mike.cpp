#include<bits/stdc++.h>
    
using namespace std;
    
#define print(p) cout<<p<<endl;
int main()
{
    int T;
    long long int N,K,i;
    cin>>T;
    while(T--)
    {
        cin>>N>>K;
        long long int arr[K];
        arr[0] = N/K;
        for(i=1 ; i< K ; i++)
            arr[i] = (int)(N-i)/K + 1;
        if(K%2!=0)
        {
            long long int sum = 0;
            sum  = sum + (arr[0]*(arr[0] - 1))/2;
            for(i=1 ; i< (float)K/2 ; i++)
            {
                sum = sum + arr[i]*arr[K-i];
            }
            cout<<sum<<endl;
        }
        else
        {
            long long int sum = 0;
            sum  = sum + (arr[0]*(arr[0] - 1))/2;
            for(i=1 ; i< K/2 ; i++)
            {
                sum = sum + arr[i]*arr[K-i];
            }
            sum = sum + (arr[K/2]*(arr[K/2] - 1))/2;
            cout<<sum<<endl;
        }
    }
    return 0;
}
