import numpy
P = map(float, raw_input().split())
print numpy.polyval(P, int(raw_input()))
