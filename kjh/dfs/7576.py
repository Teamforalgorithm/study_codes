import sys

M, N = map(int, sys.stdin.readline().split())
graph = []
seeds = []

for i in range(N):
    row = list(map(int, sys.stdin.readline().split()))
    for j, val in enumerate(row):
        if val == 1:
            seeds.append((j, i))
    graph.append(row)

count = 0
while len(seeds) > 0:
    count += 1
    temp = []
    for key, (j, i) in enumerate(seeds):
        for dx, dy in [(-1, 0), (0, -1), (1, 0), (0, 1)]:
            if ((j + dx) >= 0) and ((j + dx) < M) and ((i + dy) >= 0) and ((i + dy) < N):
                if graph[i + dy][j + dx] == 0:
                    temp.append((j + dx, i + dy))
                    graph[i + dy][j + dx] = 1
    seeds = temp

for i in range(N):
    for j in graph[i]:
        if j == 0:
            count = 0

print(count - 1)
