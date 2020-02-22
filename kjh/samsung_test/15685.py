import sys

N = int(sys.stdin.readline())
direction_map = [(1, 0), (0, -1), (-1, 0), (0, 1)]
grid = set([])
count = 0


class Curve:
    def __init__(self, start, dir, gen):
        self.points = [start]
        self.dir = dir
        self.gen = gen

    def drawPoints(self):
        cursor = (self.points[0][0] + direction_map[self.dir][0],
                  self.points[0][1] + direction_map[self.dir][1])
        for _ in range(self.gen):
            # print(cursoe
            amount = len(self.points)
            self.points.append(cursor)
            for x, y in reversed(self.points[:amount]):
                point = (-(y - cursor[1]) + cursor[0],
                         x - cursor[0] + cursor[1])
                self.points.append(point)
            cursor = self.points.pop()
            # print(cursor, self.points)
        self.points.append(cursor)
        grid.update(self.points)

        # return self.points


for _ in range(N):
    x, y, d, g = map(int, sys.stdin.readline().split())
    curve = Curve((x, y), d, g)
    curve.drawPoints()

for x, y in grid:
    if (x + 1, y) in grid:
        if (x + 1, y + 1) in grid:
            if (x, y + 1) in grid:
                count += 1

print(count)
