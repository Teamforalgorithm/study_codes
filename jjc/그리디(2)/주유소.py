import sys
import heapq
input = lambda: sys.stdin.readline().strip()

n = int(input())
ans = 0
road = list(map(int, input().split()))
heap = []
price = list(map(int, input().split()))
print(price)
print(road)
for i in range(n):
  heapq.heappush(heap, price[i])
  ans += (heapq.heappop(heap) * road[i])

print(ans)



