A = "875361268549483279131"
def numDecodings(A):

    def possible_two(i):
        if i == len(A)-1:
            return False
        return int(A[i:i+2]) in range(1, 26+1)

    dp = ["_" for _ in range(len(A))]
    if A[-1] == '0':
        dp[-1] = 0
    else:
        dp[-1] = 1

    i = len(A) - 2
    while i >= 0:
        
        for j in range(len(A)):
            print(A[j], end = " ")
        print("")
        for j in range(len(dp)):
            print(dp[j], end = " ")
        print("")
        for j in range(len(dp)):
            if i != j:
                print(" ", end = " ")
            else:
                print("i", end = " ")
        print("\n", end = "\n")


        if A[i] == '0':
            if int(A[i-1]) not in [1, 2]:
                return 0
            dp[i-1] = dp[i+1]
            i -= 2
            continue
        dp[i] = dp[i+1]
        if possible_two(i):  # eg 21
            dp[i] += dp[i+2]

        i -= 1
    print(dp)
    return dp[0] % (10**9 + 7)

def numDecodings2(A):
    if A[0]=='0':
        return 0
    d=[0]*(len(A)+1)
    d[0]=1
    d[1]=1
    for i in range(1,len(A)):
        g=int (A[i-1]+A[i])
        print(d, f"{i=}")
        if A[i]=='0' and(g!=10 and g!=20) :
            return 0
        elif g==10 or g==20 :
            d[i+1]=d[i-1]
        elif g>10 and g<=26 :
            d[i+1]=d[i]+d[i-1]
        else : 
            d[i+1]=d[i]
    

    print(d[len(A)]); 
numDecodings(A)
numDecodings2(A)