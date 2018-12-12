from math import sqrt
def fun(n):
    return sum(map(int,list(str(n))))
n = input()
t = n
facs = []
for i in range(2,int(sqrt(t))+1):
    while(n%i==0):
        facs.append(i)
        n/=i
if n>1:
    facs.append(n)
if sum(map(fun,facs)) == fun(t):
    print 1
else:
    print 0
    