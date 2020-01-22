import sys

N, M = map(int, sys.stdin.readline().split())

graph = []
# visited = [[0] * M for i in range(N)]
# Not solved
minPath = N * M

for y in range(N):
    row = list(sys.stdin.readline())
    graph.append(row)


def findPath(x, y, level, hasBroken, visited, path):
    global minPath
    global graph

    if visited[y][x]:
        return
    visited[y][x] = 1
    print(level, x, y, visited)
    print(path)

    if (x == (M - 1)) and (y == (N - 1)):
        if level < minPath:
            minPath = level - 1
        return
    for dx, dy in [(0, 1), (1, 0), (0, -1), (-1, 0)]:
        if ((x + dx) >= M) or ((x + dx) < 0) or ((y + dy) < 0) or ((y + dy) >= N):
            continue

        if int(graph[y + dy][x + dx]) == 1:
            if hasBroken:
                continue
            else:
                findPath(x + dx, y + dy, level + 1,
                         True, visited, path + [(x, y)])
        else:
            findPath(x + dx, y + dy, level + 1,
                     hasBroken, visited, path + [(x, y)])


findPath(0, 0, 0, False, [[0] * M for i in range(N)], [])

if minPath == N * M:
    print(-1)
else:
    print(minPath)
