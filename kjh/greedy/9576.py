# Runtime Error
import sys
import heapq

case = int(sys.stdin.readline())

for i in range(case):
    N, M = map(int, sys.stdin.readline().split())
    heap = []
    visited = [False] * M
    count = 0
    for j in range(M):
        val = tuple(map(int, sys.stdin.readline().split()))
        heapq.heappush(heap, (val[1], val[0]))
    
    while len(heap):
        j = heapq.heappop(heap)
        for k in range(j[1], j[0] + 1):
            if not visited[k - 1]:
                visited[k - 1] = True
                count += 1
                break

    print(count)
