# Enter your code here. Read input from STDIN. Print output to STDOUT
import numpy

N, M = map(int, input().split())

A = numpy.array([list(map(int, input().split())) for n in range(N)])
B = numpy.array([list(map(int, input().split())) for n in range(N)])

print (A + B)
print (A - B)
print (A * B)
print (A // B)
print (A % B)
print (A ** B)
