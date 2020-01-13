import sys
input = sys.stdin.readline

def dfs(x, y, arr, cnt):
  global ans

  for i in range(4):
    nx = x + dx[i]
    ny = y + dy[i]
    if nx>=0 and nx<r and ny>=0 and ny<c and arr[nx][ny] not in dic:
      dic.add(arr[nx][ny])
      dfs(nx, ny, arr, cnt+1)
      ans = max(cnt+1, ans)
      dic.remove(arr[nx][ny])

if __name__ == "__main__":    
  dx = [ -1, 1, 0, 0 ]
  dy = [ 0, 0, 1, -1 ]

  r, c = map(int, input().split())
  dic = set()
  ans = 1
  arr = []
  for _ in range(r):
    tmp = input().strip()
    arr.append(tmp)
  dic.add(arr[0][0])
  dfs(0, 0, arr, 1)
  print(ans)
      