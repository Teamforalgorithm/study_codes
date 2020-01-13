import sys
input = sys.stdin.readline

n, m = map(int, input().split())

maps = []

for _ in range(n):
  maps.append(list(map(int, input().split())))

chicken = [ (nx, ny) for nx, row in enumerate(maps) for ny, val in enumerate(row) if val == 0 ]
home = [ (nx, ny) for nx, row in enumerate(maps) for ny, val in enumerate(row) if val == 1 ]
print(chicken)
print(home)
