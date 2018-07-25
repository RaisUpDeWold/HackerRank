from __future__ import print_function
if __name__ == '__main__':
    n = int(raw_input())
    list(map(lambda i: print(i, end=''), [i for i in range(1, n + 1)]))
