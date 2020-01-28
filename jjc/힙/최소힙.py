import sys
import heapq
input = lambda: sys.stdin.readline().strip()

n = int(input())
heap = []

for _ in range(n):
  num = int(input())
  if num != 0:
    heapq.heappush(heap, num)
  else:
    try:
      print(heapq.heappop(heap))
    except:
      print(0)asdasdsad




