#include <cmath>
#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int t,n;
    cin>>t;
    for(int l=1;l<=t;l++){
        cin>>n;
        int product = 1;
        for(int i=1;i<n;i++)
        {
            int x;
            cin>>x;
            product=(x*product)%1234567;
        }
        cout<<product<<endl;
    }
    return 0;
}
