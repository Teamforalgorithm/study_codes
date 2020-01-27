import sys
import heapq

N = int(sys.stdin.readline())
heap = []

for i in range(N):
    heapq.heappush(heap, int(sys.stdin.readline()))

sum = 0
while len(heap) >= 2:
    two = heapq.heappop(heap) + heapq.heappop(heap)
    sum += two
    heapq.heappush(heap, two)
    # print(heap)

# sum += heapq.heappop(heap)

# if len(heap) < 2:
#     sum = heapq.heappop(heap)
# else:
#     sum = heapq.heappop(heap) + heapq.heappop(heap)
#     print(sum)
# while len(heap):
#     sum += heapq.heappop(heap)
#     print(sum)

print(sum)
