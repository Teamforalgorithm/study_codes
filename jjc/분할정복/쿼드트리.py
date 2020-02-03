import sys
input = lambda: sys.stdin.readline().strip()

n = int(input())
maps = []
for _ in range(n):
  maps.append(list(map(int, input())))

ans = []

def tree(x, y, n):
  tmp = maps[x][y]
  ret = []
  for i in range(n):
    for j in range(n):
      if tmp != maps[x + i][y + j]:
        ret.append("(")
        ret.extend(solve(x, y, n))
        ret.append(")")
        return ret
  return [str(tmp)]

def solve(x, y, n):
  ret = []
  ret.extend(tree(x, y, n//2))
  ret.extend(tree(x, y + n//2, n//2))
  ret.extend(tree(x + n//2, y, n//2))
  ret.extend(tree(x + n//2, y + n//2, n//2))
  return ret

ans.extend(tree(0, 0, n))
print(''.join(ans))
