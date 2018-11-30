#include <cstdio>
#include <cassert>

long long gcd(long long a, long long b)
{
    return b ? gcd(b, a % b) : a;
}
    
// 2 ^ b modulo mod
long long power(long long b, long long mod)
{
    if(b < 62) return (1LL << b) % mod;
    long long ret = power(b >> 1LL, mod);
    ret = (ret * ret) % mod;
    if(b & 1LL) ret = (ret << 1LL) % mod;
    return ret;
}
    
// Euler totient function
long long phi(long long n)
{
    long long ret = n;
    for(long long i = 2; i * i <= n; ++i)
        if(n % i == 0)
        {
            ret -= ret / i;
            while(n % i == 0) n /= i;
        }
    if(n > 1) ret -= ret / n;
    return ret;
}
    
// Returns the order of 2 modulo n
// n has to be odd
long long f(long long n)
{
    long long ph = phi(n), ret = ph;
    
//    The order divides phi(n)
//    so check all divisors
//    and return the minimum
    for(long long d = 1; d * d <= ph; ++d)
        if(ph % d == 0)
        {
//            optimization - return the minimum
//            answer immmediately if it is found
            if(power(d, n) == 1) return d;
    
//            otherwise update the answer
            if(power(ph/d, n) == 1)
                if(ph/d < ret)
                    ret = ph/d;
        }
    return ret;
}
    
int main()
{
    int t;
    scanf("%d", &t);
    assert(t <= 1000);
    
    while(t--)
    {
        long long n, a;
        scanf("%lld%lld", &n, &a);
        assert(n <= 1000000000);
        assert(a != 0 and a >= -n and a <= n);
    
        if(a < 0) a += 2 * n + 1;
        long long nn = (2 * n + 1) / gcd(a, 2 * n + 1);
        //We need to find the order of 2 modulo nn
    
        printf("%lld\n", 2 * n - f(nn));
    }
    return 0;
}
