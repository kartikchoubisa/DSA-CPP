from itertools import accumulate

def solve():
    A = [int(x) for x in input().split()]
    if sum(A) % len(A) != 0:
        return -1
    else:
        av = sum(A) // len(A)
        # ans = abs(max(accumulate((e - av for e in A), initial = 0), key = abs))
        s = 0
        ans = 0
        for e in A:
            s += e - av
            if abs(s) > ans:
                ans = abs(s)

        return ans

def get():
    while True:
        n = int(input())
        if n == -1:
            return
        else:
            print(solve())
        input()

get()