import sys

T = int(sys.stdin.readline())

for _ in range(T):
    N, K = map(int, sys.stdin.readline().split())
    D = list(map(int, sys.stdin.readline().split()))
    descendants = [[] for _ in range(N)]
    indegrees = [0] * N
    queue = []
    result = []
    time = 0

    for __ in range(K):
        A, B = map(int, sys.stdin.readline().split())
        descendants[A - 1].append(B - 1)
        indegrees[B - 1] += 1

    target = int(sys.stdin.readline())

    for i in range(N):
        if indegrees[i] == 0:
            queue.append(i)

    while queue:
        print(queue, indegrees, descendants)
        maximum = 0
        for key, val in enumerate(indegrees):
            if val == 0:
                maximum = max(D[key], maximum)
                queue.remove(key)
                for j in descendants[key]:
                    print(j, indegrees)
                    indegrees[j] -= 1
                    if indegrees[j] == 0:
                        queue.append(j)
        print(maximum)
        time += maximum
        maximum = 0

    print(time)
