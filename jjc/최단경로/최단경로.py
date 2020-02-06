# BOJ 1753 - 최단경로
import sys
from heapq import heappush, heappop
input = lambda: sys.stdin.readline().strip()
INF = 1e9

def dijkstra(v, k, g):
  dist = [INF] * v
  dist[k - 1] = 0
  q = []
  heappush(q, [0, k-1])

  while q:
    cost, pos = heappop(q)

    if dist[pos] < cost:
      continue

    for p, c in g[pos]:
      # v, w 해당 인덱스에서 v로 가는 가중치 c인 간선
      c += cost
      if c < dist[p]:
        # 가중치가 더 낮을 때만 교체를하고 아니면 이전 값 그대로
        dist[p] = c
        heappush(q, [c, p])

  return dist


V, E = map(int, input().split())
K = int(input())
graph = [[] for _ in range(V)]
for _ in range(E):
  u, v, w = map(int, input().split())
  graph[u-1].append([v-1, w])
print(graph)
for d in dijkstra(V, K, graph):
  print(d if d != INF else "INF")
