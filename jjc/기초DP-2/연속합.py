import sys
input = lambda: sys.stdin.readline().strip()

n = int(input())
arr = list(map(int, input().split()))
ans = -1001

dp = [0 for _ in range(n+1)]

for i in range(n):
  dp[i] = max(dp[i-1] + arr[i], arr[i])
  ans = max(ans, dp[i])
print(ans)
