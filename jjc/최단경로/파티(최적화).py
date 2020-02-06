from heapq import heappush, heappop
import sys
input = lambda: sys.stdin.readline().strip()

INF = 1e9
n, m, x = map(int, input().split())
dist = [[INF]*2 for _ in range(n)]
a = [[] for _ in range(n)]
b = [[] for _ in range(n)]
for i in range(m):
  u, v, w = map(int, input().split())
  a[u-1].append([v-1, w])
  b[v-1].append([u-1, w])

def dijkstra(k, direct):
  pq = []
  heappush(pq, (0, x-1))
  dist[x-1][direct] = 0
  while pq:
    cost, now = heappop(pq)
    if dist[now][direct] < cost:
      continue
    for nxt, ncost in k[now]:
      ncost += cost
      if dist[nxt][direct] > ncost:
        dist[nxt][direct] = ncost
        heappush(pq, (ncost, nxt))

dijkstra(a, 0)
dijkstra(b, 1)
ans = 0
for i in range(n):
  ans = max(ans, sum(dist[i]))
print(ans)

