import sys
input = sys.stdin.readline

dx = [-1, 1, 0, 0]
dy = [0, 0, 1, -1]

def pretty_print(arr):
  print()
  for i in arr:
    if i == ' ':
      print('True')
    print(i)

# 집: 1, 집 없음: 0 
# 연결되었다: 좌우 or 아래 위로 다른 집이 있는 경우 대각선은 연결 X

def bfs(arr, cnt, x, y):
  if maps[x][y] == 0:
    return -1
  maps[x][y] = 0
  que = []
  que.append((x, y))

  while len(que) > 0:
    x, y = que.pop()  
    for i in range(4):
      nx = x + dx[i]
      ny = y + dy[i]
      if nx>=0 and nx<n and ny>=0 and ny<n and arr[nx][ny] == 1:
        if arr[nx][ny] == 1:
          arr[nx][ny] = 0
          que.append((nx, ny))
          cnt += 1
  return cnt

n = int(input())
maps = []
for _ in range(n):
  maps.append(list(map(int, " ".join(input().strip()).split())))

print

item_list = [(nx, ny) for nx, row in enumerate(maps) for ny, val in enumerate(row) if val == 1]
cnt = 0
ans = []
for x, y in item_list:
  result = bfs(maps, cnt+1, x, y)
  if result != -1:
    ans.append(result)

print(len(ans))
for i in sorted(ans):
  print(i)
  




