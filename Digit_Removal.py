import math

t = int(input())
for _ in range(t):
    N,D = [int(x) for x in input().split()]
    N_list = [x for x in str(N)]

    if D==0:
        flagged = False
        for i,dig in enumerate(N_list):
            if dig == "0":
                flagged = True
                N_list[i] = "1"
            elif flagged:
                N_list[i] = "1"
        print(int("".join(N_list))-N)

    else:
        N_list = N_list[::-1]
        for r in [x for x in range(int(math.log(N,10))+1)][::-1]:
            if N_list[r] == str(D):
                print(10**r-N%10**r)
                break
        else:
            print(0)
