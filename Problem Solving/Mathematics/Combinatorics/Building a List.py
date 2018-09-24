#!/usr/bin
t=int(raw_input())
for f in range(0,t):
    n=int(raw_input())
    s=str(raw_input())
    n=len(s)
    a=[]
    for i in range(1,2**n):
        test=str(bin(i))[2:][::-1]
        out=""
        for i in range(0,len(test)):
            if test[i]=='1':
                out=out+str(s[i])
        a.append(out)
    a.sort()
    for i in a:
        print i
        