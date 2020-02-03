# TODO: change heap sort to .sort() using cmp(str a, str b)
import sys
import heapq

K, N = map(int, sys.stdin.readline().split())
heap = []
sum = ''
max = (0,0)

for _ in range(K):
    val = int(sys.stdin.readline())
    if max[1] < val:
        max = (-float(str('%e' % val)[:8]), val)
    heapq.heappush(heap, (-float(str('%e' % val)[:8]), val))

for _ in range(N - K):
    heapq.heappush(heap, max)

while len(heap):
    val = heapq.heappop(heap)
    sum += str(val[1])
    
print(sum)
\


