import sys
import heapq

N = int(sys.stdin.readline())
heap = []

for i in range(N):
    val = int(sys.stdin.readline())
    if val == 0:
        if len(heap):
            print(heapq.heappop(heap)[1])
        else:
            print(0)
    else:
        heapq.heappush(heap, (-val, val))
