import numpy
N_M = map(int, raw_input().split())
a = numpy.array([map(int, raw_input().split()) for i in range(N_M[0])])
print numpy.max(numpy.min(a, axis = 1))
