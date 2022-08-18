dp = [0 for _ in range(100)]
dp[0] = 1

N = 10
K = 2

for i in range(1,K+1):
    dp[i] = sum(dp[:i])

for i in range(K+1, N):
    dp[i] = sum(dp[i-K:i])

print(dp)
