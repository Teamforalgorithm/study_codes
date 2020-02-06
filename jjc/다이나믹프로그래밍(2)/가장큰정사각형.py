import sys
input = lambda: sys.stdin.readline().strip()

dx = (-1, -1, 0)
dy = (0, -1, -1)

n, m = map(int, input().split())
dp = [[0]*1001 for _ in range(1001)]
maps = [[0]*1001 for _ in range(1001)]

ans = 0

for i in range(n):
  val = list(map(str, input()))
  for j in range(m):
    maps[i][j] = int(val[j])
    if maps[i][j] == 1:
      dp[i][j] = 1
      ans = 1


for i in range(n):
  for j in range(m):
    if maps[i-1][j] == 1 and maps[i-1][j-1] == 1 and maps[i][j-1] == 1:
      dp[i][j] = min(dp[i-1][j-1], dp[i-1][j])
      dp[i][j] = min(dp[i][j], dp[i][j-1]) + 1

  ans = max(ans, dp[i][j])


print(ans*ans)