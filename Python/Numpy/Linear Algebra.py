import numpy
N = int(raw_input())
A = numpy.array([map(float, raw_input().split()) for i in range(N)])
print numpy.linalg.det(A)
