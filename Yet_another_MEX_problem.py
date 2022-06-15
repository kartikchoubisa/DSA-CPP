import math

t = int(input())
for _ in range(t):
    N,K = [int(x) for x in input().split()]
    A = [int(x) for x in input().split()]
    # find length L of subarr so that Kth min may correspond to that subarray
    L = 1
    S_L = N
    while S_L<K:
        S_L += N - (L-1)
        L+=1
    
    #finding mex of all subarrays of length L?
    # rank (S_L - (N-L-1) + 1)th to S_Lth
    # no. of subarrys (of length L) are N-L-1
    # max mux : L, and total possible muxes are L+1. (0,1,2,.. L-1,L)
    counts = dict(((x,0) for x in range(L+1)))
    for i in range(N-L-1):
        for j in range(i,i+L):
            subarr = A[i:j+1]
            table = [True for e in subarr]
            




