#include <bits/stdc++.h>
using namespace std;

int n, k;
int tab[107];
int res;
int a = 1, b;

int main() {
    scanf("%d%d", &n, &k);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &tab[i]);
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= tab[i]; j++) {
            if (j == a) {
                res++;
            }
            b++;
            if (j == tab[i] || b == k) {
                b = 0;
                a++;
            }
        }
    }
    printf("%d\n", res);
    return 0;
}
