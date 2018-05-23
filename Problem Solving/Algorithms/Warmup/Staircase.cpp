#include <bits/stdc++.h>

using namespace std;

void staircase(int n) {
    // Complete this function
    int i, j;
    for (i = n - 1; i >= 0; i --) {
        for (j = 0; j < i; j ++) {
            cout << " ";
        }
        for (j = 0; j < n - i; j ++) {
            cout << "#";
        }
        cout << endl;
    }
}

int main() {
    int n;
    cin >> n;
    staircase(n);
    return 0;
}
