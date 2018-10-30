#include <bits/stdc++.h>

using namespace std;

long long maxMoves(long long n) {
    vector <long long> primes;
    
    for (long long d = 2; d * d <= n; d++) while (n % d == 0) {
        primes.push_back(d);
        n /= d;
    }
    
    if (n > 1) {
        primes.push_back(n);
    }
    
    reverse(primes.begin(), primes.end());
    
    long long answer = 1;
    long long curr = 1;
    
    for (long long p : primes) {
        curr *= p;
        answer += curr;
    }
    
    return answer;
}

int main() {
    ios_base::sync_with_stdio(0);
    
    int n;
    cin >> n;

    long long result = 0;
    while (n--) {
        long long x;
        cin >> x;
        
        result += maxMoves(x);
    }
    
    cout << result;
    return 0;
}
