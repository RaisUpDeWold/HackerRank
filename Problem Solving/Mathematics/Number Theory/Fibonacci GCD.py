from fractions import gcd
mod = 10**9+7
class _:
    def __init__(a, x=0, y=0): a.x, a.y = x, y
    __add__ = lambda a, b: _((a.x+b.x)%mod, (a.y+b.y)%mod)
    __mul__ = lambda a, b: _((a.x*b.x+5*a.y*b.y)%mod, (a.x*b.y+a.y*b.x)%mod)
    __pow__ = lambda a, b: a if b == 1 else a*a**(b-1) if b&1 else (a*a)**(b>>1)
print(_(mod+1>>1,mod+1>>1)**reduce(gcd,(input() for i in xrange(input())))).y*2%mod
