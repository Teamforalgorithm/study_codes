#NOTE: not solved yet
import sys

N = int(sys.stdin.readline().split())
graph = []

for i in range(3):
    row = list(map(int, sys.stdin.readline().split()))
    graph.append(row)

for i in range(N):
    min_val = 3000
    for j in range(3):
        for k in range(3):
            for l in range(3):
                if graph[j][i] + graph[][i+1] + [][i+2] < min_val:
                    min_val = graph[j][i] + graph[k][i+1] + [l][i+2]
                    