# NOTE: Floyd-Warshall algorithm used.
import sys

N, M = map(int, sys.stdin.readline().split())
D = [0] * N
P = [0] * N

for i in range(N):
    D[i] = [float("inf")] * N
    D[i][i] = 0
    P[i] = [float("inf")] * N

for _ in range(M):
    A, B, C = map(int, sys.stdin.readline().split())
    D[A - 1][B - 1] = C
    P[A - 1][B - 1] = A - 1

print("input: ")
for k in range(N):
    print(D[k])
print()
for k in range(N):
    print(P[k])
print()

for k in range(N):
    for i in range(N):
        for j in range(N):
            if P[i][j] == float("inf"):
                continue
            if D[i][j] > D[i][k] + D[k][j]:
                D[i][j] = D[i][k] + D[k][j]
                P[i][j] = k
                # for l in range(N):
                #     print(D[l], "   ", i, k, j)

print("result: ")
for i in range(N):
    for j in range(N):
        print("%8d" % D[i][j], end='')
    print()

print()

for i in range(N):
    for j in range(N):
        print("%8d" % P[i][j], end='')
    print()
