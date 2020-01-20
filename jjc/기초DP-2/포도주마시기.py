import sys
input: lambda: sys.stdin.readline().strip()

n = int(input())
# dp = [0] * (10001)
dp = [0]
acc = [0] * (n+1)
for _ in range(n):
  dp.append(int(input()))

for i in range(1, n+1):
  if i==1:
    acc[1] = dp[1]
  elif i==2:
    acc[2] = dp[1] + dp[2]
  else:
    acc[i] = max(acc[i-3] + dp[i-1] + dp[i], acc[i-2] + dp[i], acc[i-1])

print(acc[-1])


