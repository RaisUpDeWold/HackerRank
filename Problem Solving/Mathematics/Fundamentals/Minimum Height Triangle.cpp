#include <iostream>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    int b, a;
    cin >> b >> a;

    if ((2*a) % b == 0) {
        cout << 2*a/b << endl;
    } else {
        cout << 2*a/b + 1 << endl;
    }
    return 0;
}
