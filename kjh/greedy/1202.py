# WRONG
import sys
import heapq

N, K = map(int, sys.stdin.readline().split())
gems = []

for i in range(N):
    gem = tuple(map(int, sys.stdin.readline().split()))
    heapq.heappush(gems, (-gem[1], gem[0]))

sum = float(0)
for i in range(K):
    weight = int(sys.stdin.readline())
    for j in gems:
        if weight >= j[1]:
            sum -= heapq.heappop(gems)[0]
            break

print(int(sum))
