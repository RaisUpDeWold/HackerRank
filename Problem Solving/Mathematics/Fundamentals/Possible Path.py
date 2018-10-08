from fractions import gcd 
for _ in range(input()): 
    a,b,x,y = [int (x) for x in raw_input().split()] 
    if gcd(x,y) == gcd (a,b): 
        print "YES" 
    else:
        print "NO"
        