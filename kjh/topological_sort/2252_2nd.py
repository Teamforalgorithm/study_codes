import sys
from collections import deque

N, M = map(int, sys.stdin.readline().split())

descendants = deque([[] for i in range(N)])
indegrees = deque([0] * N)
queue = []
result = deque([])

for _ in range(M):
    A, B = map(int, sys.stdin.readline().split())
    descendants[A - 1].append(B - 1)
    indegrees[B - 1] += 1

for i in range(N):
    if indegrees[i] == 0:
        queue.append(i)

while queue:
    for i in queue:
        if indegrees[i] == 0:
            queue.remove(i)
            result.append(i + 1)
            for j in descendants[i]:
                indegrees[j] -= 1
                if indegrees[j] == 0:
                    queue.append(j)

print(*result)

# NOTE find out why queue returns ERROR when queue = deque([])
# NOTE review line 25 ~ 28
