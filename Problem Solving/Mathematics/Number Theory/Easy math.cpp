#include<bits/stdc++.h>
    
using namespace std;
    
int main()
{
    int T;
    int N;
    int a,b,i;
    cin>>T;
    assert(1<=T);
    assert(T<=1000);
    while(T--)
    {
        cin>>N;
         assert(1<=N);
         assert(N<=100000);
        if(N==1 || N ==2 || N==4)
        {
            cout<<2<<endl;
            continue;
        }
        int A[N];
        A[0] = 0;
        for(i= 1 ; i < N ; i++)
            A[i] = -1;
        A[4%N] = 1;
        int temp = 4%N;
        for(i=2 ; i<=N+2 ; i++)
        {
            if(A[(temp*10 + 4) % N] != -1)
            {
                a = i;
                b = A[(temp*10 + 4) % N] ;
                break;
            }
            else
            {
                A[(temp*10 + 4) % N]  = i;
                temp = (temp*10 + 4)%N;
            }
        }
        cout<<2*a-b<<endl;
    }
    return 0;
}
