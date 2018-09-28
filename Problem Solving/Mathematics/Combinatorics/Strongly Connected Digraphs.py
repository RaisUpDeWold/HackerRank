mod = 10**9+7
MAX = 1001

C = [[0]*MAX for i in xrange(MAX)]
e = [0]*MAX
s = [0]*MAX
for n in xrange(MAX):
    for r in xrange(n+1):
        C[n][r] = 1 if r == 0 or r == n else (C[n-1][r-1] + C[n-1][r]) % mod
    e[n] = (pow(2, n*(n-1), mod) - sum(C[n][i]*pow(2, (n-1)*(n-i), mod)*e[i] for i in xrange(1,n))) % mod
    s[n] = (e[n] + sum(C[n-1][i-1]*s[i]*e[n-i] for i in xrange(1,n))) % mod

for cas in xrange(input()):
    print s[input()]
    