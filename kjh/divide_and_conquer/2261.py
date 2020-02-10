import sys

N = int(sys.stdin.readline())
points = []
min_dist = 200000000

for _ in range(N):
    points.append(tuple(map(int, sys.stdin.readline().split())))

for i in range(1, N):
    for j in range(0, i):
        min_dist = min((points[i][0] - points[j][0]) **
                       2 + (points[i][1] - points[j][1])**2, min_dist)
print(min_dist)
