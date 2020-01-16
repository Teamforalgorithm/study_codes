import sys
input = sys.stdin.readline

# 상 하 좌 우
dx = [-1, 1, 0, 0]
dy = [0, 0, 1, -1]

def zero_check(arr):
  for row in arr:
    if 0 in row:
      return 1
  return -1

# M은 상자의 가로 칸 수, N은 상자의 세로 칸 수
m, n = map(int, input().split())
maps = []
ans = 0
for _ in range(n):
  maps.append(list(map(int, input().split())))

tomato = [(nx, ny) for nx, row in enumerate(maps) for ny, val in enumerate(row) if val == 1]

while(len(tomato) > 0):
  new_tomato = []

  for idx, cod in enumerate(tomato):
    x, y = cod
    for i in range(4):
      nx = x + dx[i]
      ny = y + dy[i]
      if nx>=0 and nx<n and ny>=0 and ny<m and maps[nx][ny] == 0:
        new_tomato.append((nx, ny))
        maps[nx][ny] = 1
  ans += 1
  tomato = new_tomato

if zero_check(maps) == -1:
  print(ans-1)
else:
  print('-1')


  
