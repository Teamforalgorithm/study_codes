import sys
import heapq
input = lambda: sys.stdin.readline()

k, n = map(int, input().split())
arr = []
heap = []
pr = 0

for _ in range(k):
  tmp = input()
  first = int(tmp[0])
  arr.append((first, tmp))
  heapq.heappush(heap, (-first, tmp))

for _ in range(len(heap)):
  if len(heap)>=0:
    print(heapq.heappop(heap)[1], end='')
