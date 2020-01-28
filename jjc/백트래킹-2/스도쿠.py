import sys
input = sys.stdin.readline
sys.setrecursionlimit(10**8)
def pretty_print():
  for row in maps:
    for val in row:
      print(val, end=' ')
    print()

# 가로 체크
def horizontal(x, val):
  if val in maps[x]:
    return False
  return True

# 세로 체크
def vertical(y, val):
  for i in range(9):
    if val == maps[i][y]:
      return False
  return True

# 박스 체크
def three(x, y, val):
  nx = x//3 * 3
  ny = y//3 * 3
  for i in range(3):  
    for j in range(3):
      if val == maps[nx+i][ny+j]:
        return False
    return True


def dfs(idx):
  if len(blank_list) == idx:
    pretty_print()
    quit()
  else:
    for i in range(1, 10):
      nx = blank_list[idx][0]
      ny = blank_list[idx][1]
      if horizontal(nx, i) and vertical(ny, i) and three(nx, ny, i):
        maps[nx][ny] = i
        dfs(idx+1)
        maps[nx][ny] = 0
      

maps = []
for _ in range(9):
  maps.append(list(map(int, input().split())))

blank_list = [(i, j) for i in range(9) for j in range(9) if maps[i][j] == 0]

dfs(0)
