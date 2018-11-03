#include <iostream>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    int t;
    cin >> t;
    for (int test = 0; test < t; test++) {
        int n;
        cin >> n;
        long long s = 0;
        for (int i = 0; i < n; i++) {
            int a;
            cin >> a;
            s += a;
        }
        cout << (s % 3 == 0 ? "Yes\n" : "No\n");
    }
}
