#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    int n;
    float fr1=0,fr2=0,fr3=0;
    cin >> n;
    vector<int> arr(n);
    for(int arr_i = 0;arr_i < n;arr_i++){
       cin >> arr[arr_i];
    }
    for(int arr_i = 0; arr_i < n; arr_i++){
        if(arr[arr_i]>0) {
            fr1++;
        }
        if(arr[arr_i]<0) {
            fr2++;
        }
        if(arr[arr_i]==0) {
            fr3++;
        }
    }
    cout.precision(6);
    cout << (fr1/n) <<'\n' ;
    cout << (fr2/n) <<'\n' ;
    cout << (fr3/n) <<'\n' ;
    return 0;
}
