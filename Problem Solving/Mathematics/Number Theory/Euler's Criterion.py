for _ in range(input()):
    a,m = map(int,raw_input().split())
    if m == 2 or a == 0:
        print "YES"
    elif pow(a,(m-1)/2,m) == 1:
        print "YES"
    else:
        print "NO"
        