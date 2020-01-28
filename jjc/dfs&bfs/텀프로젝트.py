import sys
sys.setrecursionlimit(10**6)
input = lambda : sys.stdin.readline().strip()


def dfs(x, cnt, step):
  global d, check, s

  while True:
    if check[x] != False:
      if step != s[x-1]:
        return 0
      return cnt - check[x]
    check[x] = cnt
    s[x-1] = step
    x = d[x]
    cnt += 1

for _ in range(int(input())):
  n = int(input())
  check = [False]*(n+1)

  d = {}
  s = list(map(int, input().split()))
  for i in range(1, n+1):
    d[i] = s[i-1]

  ans = 0
  for i in d:
    if check[i] == False:
      ans += dfs(i, 1, i);

  print(n-ans)


