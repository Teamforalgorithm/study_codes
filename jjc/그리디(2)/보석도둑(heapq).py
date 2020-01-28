import sys
import heapq
input = lambda: sys.stdin.readline().strip()

n, k = map(int, input().split())
heap = []
for _ in range(n):
  m, v= map(int, input().split())
  heapq.heappush(heap, (m, v))

c = []
for _ in range(k):
  heapq.heappush(c, int(input()))

ans = 0
use_list = [] # 현재 c보다 작은 보석들

for _ in range(k):
  capa = heapq.heappop(c) # 가방의 최소를 빼주고
  
  while heap and capa >= heap[0][0]:
    (m, v) = heapq.heappop(heap)
    heapq.heappush(use_list, -v)
  
  if use_list: #heap 최소보다는 작지만 넣을 수는 있는 보석들이 있는 경우
    ans -= heapq.heappop(use_list)
  elif not heap:
    break

print(ans)
