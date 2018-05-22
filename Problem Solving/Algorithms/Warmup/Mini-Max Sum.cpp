#include <bits/stdc++.h>

using namespace std;

void miniMaxSum(vector <int> arr) {
    // Complete this function
    int min = arr[0], max = arr[0];
    long sum = 0;
    int i;
    for (i = 0; i < 5; i ++) {
        sum += arr[i];
        if (min > arr[i]) min = arr[i];
        if (max < arr[i]) max = arr[i];
    }
    cout << sum - max << " " << sum - min << endl;
}

int main() {
    vector<int> arr(5);
    for(int arr_i = 0; arr_i < 5; arr_i++){
       cin >> arr[arr_i];
    }
    miniMaxSum(arr);
    return 0;
}
