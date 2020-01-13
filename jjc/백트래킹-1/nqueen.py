import sys
input = sys.stdin.readline

# x번째 행에 놓은 퀸에 대한 검증
def check(x):
  # 이전 행에서 놓았던 모든 퀸들을 확인한다.
  for i in range(x):
    # 위쪽 혹은 대각선을 확인
    if row[x] == row[i]:
      return False
    if abs(row[x] - row[i]) == x-i:
      return False
  return True

# x번째 행에 대하여 처리
def dfs(x):
  global ans
  if x==n:
    ans += 1
  else:
    # x번째 행의 각 열에 퀸을 둔다고 가정한다.
    for i in range(n):
      row[x] = i
      # 해당 위치에 퀸을 두는게 가능한 경우
      if check(x):
        dfs(x+1)


n = int(input())
row = [0] * n
ans = 0
dfs(0)
print(ans)

    


