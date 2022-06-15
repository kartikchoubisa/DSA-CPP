import math

t = int(input())
for x in range(t):
    N = int(input())
    p = math.floor(math.log(N, 2))
    print(max([2**(p-1),N-2**p+1]))