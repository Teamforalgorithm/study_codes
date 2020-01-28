import sys

M, N, K = map(int, sys.stdin.readline().split())
graph = [[0] * N for i in range(M)]

sys.setrecursionlimit(10 ** 6)

for k in range(K):
    a, b, c, d = map(int, sys.stdin.readline().split())
    for y in range(b, d):
        for x in range(a, c):
            graph[y][x] = -1

# for i in range(M):
#     print(graph[i])
# print()


def flood(x, y, group, visited):
    if (graph[y][x] != 0) or (visited[y][x] != 0):
        return
    graph[y][x] = group
    visited[y][x] = 1

    for dx, dy in [(1, 0), (-1, 0), (0, 1), (0, -1)]:
        if ((x + dx) < 0) or ((x + dx) >= N) or ((y + dy) < 0) or ((y + dy) >= M):
            continue
        flood(x + dx, y + dy, group, visited)


group = 0
for y in range(M):
    for x in range(N):
        if graph[y][x] == 0:
            group += 1
            flood(x, y, group, [[0] * N for i in range(M)])

counts = [0] * group
for y in range(M):
    for x in range(N):
        if graph[y][x] > 0:
            counts[graph[y][x] - 1] += 1

# for i in range(M):
#     print(graph[i])
# print()

print(group)
print(*sorted(counts))
