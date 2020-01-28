import sys

n, k = list(map(int, sys.stdin.readline().split()))
value = []
for i in range(n):
    temp = int(sys.stdin.readline())
    value.append(temp)

dp = [0 for i in range(10001)]
dp[0] = 1
for i in value:
    for j in range(i, k + 1):
        dp[j] += dp[j - i]

print(dp[k])
