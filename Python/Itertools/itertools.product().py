# Enter your code here. Read input from STDIN. Print output to STDOUT
from itertools import product

A = raw_input().split()
A = list(map(int, A))
B = raw_input().split()
B = list(map(int, B))

for i in product(A, B):
    print i,
    