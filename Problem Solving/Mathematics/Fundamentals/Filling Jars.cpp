#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include<bits/stdc++.h>
using namespace std;
    
    
int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    long long int N,M;
    long long int i,a,b,k;
    cin>>N>>M;
    assert(3<=N);
    assert(N<=10000000);
    assert(1<=M);
    assert(M<=100000);
    long long int sum1 = 0;
    for(i=0 ; i< M ; i++)
    {
            cin>>a;
            cin>>b;
            cin>>k;
            assert(1<=a);
            assert(a<=b);
            assert(b<=N);
            assert(0<=k);
            assert(k<=1000000);
            sum1 += (b-a+1)*k;
            
    }
    cout<<sum1/N<<endl;
    return 0;
}
