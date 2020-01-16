import sys
input = lambda: sys.stdin.readline().strip()

def solve(arr, n):
  dp = []
  dp.append(arr[0])
  for i in range(1, 3):
    if i==1:
      dp.append(max(dp[i-1] + arr[i], arr[i]))
      continue
    dp.append(max(dp[i-2] + arr[i], arr[i-1] + arr[i]))
  
  for i in range(3, n):
    # i번째 계단으로 올라오기 위해 max(직전 계단을 밟은 경우, 직전 계단을 밟지 않은 경우)
    dp.append(max(arr[i] + arr[i-1] + dp[i-3], arr[i] + dp[i-2]))
  print(dp[-1])

n = int(input())
arr = []
for _ in range(n):
  arr.append(int(input()))

solve(arr, n)