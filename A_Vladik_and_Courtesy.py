import math;
import itertools as it

def m1(a,b):
    if a == 0: return("Vladik")
    elif b == 0: return("Valera")
    else:
        if int(math.sqrt(a+1)) <= int(math.sqrt(b-1)):
            return("Vladik")
        else:
            return("Valera")

def m2(a,b):
    i,j=1,1
    sa,sb=0,0
    while True:
        sa = i**2
        i+=1
        if sa > a:
            return("Vladik")
            break
        sb = j**2 + j
        j+=1
        if sb> b:
            return("Valera")
            break
for a,b in it.product(range(1,100), range(1,100)):
    ans1 = m1(a,b)
    ans2 = m2(a,b)
    if ans1 != ans2:
        print(a,b)
        print(f'{ans1=}', end=" ")
        print(f'{ans2=}')
        print("")

