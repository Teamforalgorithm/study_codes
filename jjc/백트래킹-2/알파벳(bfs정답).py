import sys
input = sys.stdin.readline

dx = [-1, 1, 0, 0]
dy = [0, 0, 1, -1]

def bfs(x, y):
  global ans
  # 동일한 경우는 한 번만 계산하기 위하여 집합 자료형 사용
  q = set()
  q.add((x, y, arr[x][y]))

  while q:
    x, y, step = q.pop()
    print(step)
    # 가장 긴 이동 거리를 저장
    ans = max(ans, len(step))

    for i in range(4):
      nx = x + dx[i]
      ny = y + dy[i]

      # 이동가능한 위치면서, 새로운 알파벳이면
      if nx>=0 and nx<r and ny>=0 and ny<c and arr[nx][ny] not in step:
        q.add((nx, ny, step+arr[nx][ny]))

r, c = map(int, input().split())
arr = []
for _ in range(r):
  arr.append(input().strip())

ans = 0
bfs(0, 0)
print(ans)