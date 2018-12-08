#include<bits/stdc++.h>

using namespace std;

int gcd(int a, int b)
{
    if(b > a)
        swap(a, b);
    while(b != 0)
    {
        int c = a % b;
        a = b;
        b = c;
    }
    return a;
}

int main()
{
    int t, n;
    vector<int> a, b;
    cin >> t;
    assert(1 <= t and t <= 10);
    while(t--)
    {
        cin >> n;
        a.resize(n);
        b.resize(n + 1);
        assert(2 <= n  and n <= 1e3);
        for(int i = 0; i < n; i++)
        {
            cin >> a[i];
            assert(1 <= a[i] and a[i] <= 1e4);
        }

        b[0] = a[0];

        for(int i = 1; i < n; i++)
            b[i] = (a[i - 1] * a[i]) / gcd(a[i - 1], a[i]);

        b[n] = a[n - 1];

        for(int i = 0; i < n; i++)
            cout << b[i] << " ";
        cout << b[n] << endl;
    }
    return 0;
}
