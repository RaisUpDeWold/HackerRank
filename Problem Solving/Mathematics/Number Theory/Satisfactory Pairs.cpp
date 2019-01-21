#include <fstream>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

const int maxn = 300100;

int a[maxn];

vector<int> d[maxn];
int p[maxn];

int main()
{


int n;
cin >> n;

p[1] = 2;
for (int i=2; i*i<n; i++)
    if (!p[i])
    {
        for (int j=i*i; j<n; j+=i)
            if (!p[j])
                p[j] = i;
    }

for (int i=2; i<n; i++)
    if (!p[i])
        p[i] = i;

d[1].push_back(1);
for (int i=2; i<n; i++)
{
    int x = i, y=0;
    for (; !(x % p[i]); x /= p[i], y++);

    for (int j=0; j < d[x].size(); j++)
        for (int t=0, z = d[x][j]; t <= y; t++, z *= p[i])
            d[i].push_back(z);

    sort(d[i].begin(), d[i].end());
}


for (int i=0; i<n; i++)
    a[i] = 0;
int ans = 0;

for (int b=2; b<n; b++)
    for (int x = n-b; x >= 1; x -= b)
        for (int i=0; i < d[x].size() && d[x][i] < b; i++)
        {
            ans += a[d[x][i]] != b;
            a[d[x][i]] = b;
        }

cout << ans << endl;



return 0;
}
