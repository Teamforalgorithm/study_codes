import sys
from heapq import heappush, heappop
input = lambda: sys.stdin.readline().strip()
INF = 1e9
n, m, x = map(int, input().split())

'''
N개의 숫자로 구분된 마을
파티에 참석하고 다시 마을로 돌아와야함
여기서 가장 많은 시간을 소비하는 학생
'''
def pretty_print(arr):
  for i in arr:
    print(i)
def dijkstra(n, start, graph):
  dist = [INF] * n
  dist[start] = 0
  q = []
  heappush(q, (0, start))
  while q:
    cost, pos = heappop(q)
    for p, c in graph[pos]:
      c += cost
      if c < dist[p]:
        dist[p] = c
        heappush(q, [c, p])
      
  return dist

graph = [[] for _ in range(n)]
for _ in range(m):
  start, end, t = map(int, input().split())
  graph[start-1].append((end-1, t))

dp = [0] * n

for i in range(n):
  ret = dijkstra(n, i, graph)
  # i번 째 마을
  if i == x-1:
    # x-1(파티가 열리는 마을)에 도착하면
    for idx, result in enumerate(ret):
      dp[idx] += result
  else:
    dp[i] += ret[x-1]

print(max(dp))

