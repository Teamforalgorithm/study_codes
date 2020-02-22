import sys

N = int(sys.stdin.readline())
direction_map = [(1, 0), (0, -1), (-1, 0), (0, 1)]
grid = set([])
count = 0

for _ in range(N):
    x, y, d, g = map(int, sys.stdin.readline().split())
    cursor = (x + direction_map[d][0], y + direction_map[d][1])
    points = [(x, y), cursor]
    for _ in range(g):
        amount = len(points)
        for x, y in reversed(points[:amount]):
            point = (-(y - cursor[1]) + cursor[0], x - cursor[0] + cursor[1])
            points.append(point)
        cursor = points[-1]
    grid.update(points)

for x, y in grid:
    if (x + 1, y) in grid:
        if (x + 1, y + 1) in grid:
            if (x, y + 1) in grid:
                count += 1

print(count)
