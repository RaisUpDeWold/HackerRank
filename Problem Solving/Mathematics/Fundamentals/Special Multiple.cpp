#include <queue>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include<assert.h>
using namespace std;
    
int back[500];
int backvertex[500];
    
int main() {
    int T;
    scanf("%d", &T);
    assert(T >= 1);
    assert(T <= 10000);
    while (T--) {
        int n;
        scanf("%d", &n);
        assert(n >= 1);
        assert(n <= 500);
        memset(back, -1, sizeof(back));
        queue<int> q;
        q.push(9 % n);
        back[9 % n] = -2;
        while (q.size()) {
            int sz = q.size();
            while (sz--) {
                int x = q.front();
                q.pop();
                int nx = (x * 10) % n;
                if (back[nx] == -1) {
                    back[nx] = 0;
                    backvertex[nx] = x;
                    q.push(nx);
                }
                
                nx = (x * 10 + 9) % n;
                if (back[nx] == -1) {
                    back[nx] = 9;
                    backvertex[nx] = x;
                    q.push(nx);
                }
            }
        }
        
        string s = "";
        int x = 0;
        while (back[x] != -2) {
            s += char(back[x] + 48);
            x = backvertex[x];
        }
        
        s += "9";
        
        reverse(s.begin(), s.end());
        cout << s << endl;
    }
    return 0;
}
