import sys
input = sys.stdin.readline
sys.setrecursionlimit(10**8)
# 상 하 좌 우
dx = [-1, 1, 0, 0]
dy = [0, 0, 1, -1]

def pretty_print(arr):
  print()
  for i in arr:
    print(i)

def zero_check(arr):
  for row in arr:
    if 0 in row:
      return 1
  return -1

def dfs(tomato):
  global ans
  global maps

  if tomato == []:
    print('-1')
    sys.exit()
  if zero_check(maps) == -1:
    print(ans)
    sys.exit()

  # 새로운 토마토 좌표들 저장
  new_tomato = []
  
  for idx, cod in enumerate(tomato):
    x, y = cod
    for i in range(4):
      nx = x + dx[i]
      ny = y + dy[i]
      if nx>=0 and nx<n and ny<m and ny>=0 and maps[nx][ny] == 0:
        new_tomato.append((nx, ny))
        maps[nx][ny] = 1
    # pretty_print(maps)
  ans += 1
  dfs(new_tomato)

# M은 상자의 가로 칸 수, N은 상자의 세로 칸 수
m, n = map(int, input().split())
maps = []
ans = 0
for _ in range(n):
  maps.append(list(map(int, input().split())))

tomato = [(nx, ny) for nx, row in enumerate(maps) for ny, val in enumerate(row) if val == 1]
dfs(tomato)
