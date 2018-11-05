import fileinput
n=0
for line in fileinput.input():
    t=int(line)
    if n>0:
        p=1
        q=10**9+1
        while q-p>=2:
            mi=(p+q)/2
            if mi**2>t:
                q=mi
            else:
                p=mi
        ans=p
        if ans%2==1:
            print 'odd'
        else:
            print 'even'
    else:
        n=int(line)
        