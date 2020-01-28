import sys

M, N, H = map(int, sys.stdin.readline().split())
graph = []
seeds = []

for k in range(H):
    temp = []
    for i in range(N):
        row = list(map(int, sys.stdin.readline().split()))
        for j, val in enumerate(row):
            if val == 1:
                seeds.append((j, i, k))
        temp.append(row)
    graph.append(temp)

neighbors = [
    (-1, 0, 0),
    (0, -1, 0),
    (0, 0, -1),
    (1, 0, 0),
    (0, 1, 0),
    (0, 0, 1),
]

count = 0
while len(seeds) > 0:
    count += 1
    temp = []
    for key, (j, i, k) in enumerate(seeds):
        for dx, dy, dz in neighbors:
            if ((j + dx) >= 0) and ((j + dx) < M) and ((i + dy) >= 0) and ((i + dy) < N):
                if ((k + dz) >= 0 and (k + dz) < H):
                    if graph[k + dz][i + dy][j + dx] == 0:
                        temp.append((j + dx, i + dy, k + dz))
                        graph[k + dz][i + dy][j + dx] = 1
    seeds = temp

for k in range(H):
    for i in range(N):
        for j in graph[k][i]:
            if j == 0:
                count = 0

print(count - 1)
