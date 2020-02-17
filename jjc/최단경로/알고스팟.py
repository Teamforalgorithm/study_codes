import sys
from heapq import heappush, heappop
input = lambda: sys.stdin.readline().strip()

INF = 1e9
dx = (-1, 1, 0, 0)
dy = (0, 0, 1, -1)

m, n = map(int, input().split())
dp = [[0] * m for _ in range(n)]
maps = [input() for _ in range(n)]

def bfs(pos):
  que = []
  x, y = pos
  check = [[False] * m for _ in range(n)]
  check[x][y] = True
  heappush(que, [0, pos])
  while que:
    v = heappop(que)
    cost = v[0]
    x, y = v[1]
    for i in range(4):
      nx = x + dx[i]
      ny = y + dy[i]
      if nx == m-1 and ny == n-1:
        print(cost)
        return
      if 0 <= nx < n and 0 <= ny < m and not check[nx][ny]:
        check[nx][ny] = True
        heappush(que, [cost+1 if maps[nx][ny] == '1' else cost, [nx, ny]])

if m == 1 and n == 1:
  print(0)  
else:
  bfs([0, 0])
