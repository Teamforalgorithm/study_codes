import sys
input = lambda: sys.stdin.readline().strip()

N, L = map(int, input().split())
maps = []
for _ in range(N):
  maps.append(list(map(int, input().split())))

def checkColumn(maps, r):
  cmp = maps[r][0]
  prevPos = (r, 0)
  slopeCheck = False
  cnt = 0
  for i in range(1, N):
    if maps[r][i] == cmp: # 이전과 동일한 값이면 계속 진행
      continue
    if (maps[r][i] - cmp) > 1: # 높이의 차가 1이상이면 경사로를 깔아도 못지나간다.
      return False
    
    if slopeCheck and (maps[r][i] - cmp) != 1:
      return False

    # prevPos에서 왼쪽 행 or 오른 쪽행의 값이 (r, c)의 값과 같이야한다.
    if (maps[r][i] - cmp) == 1:
      if maps[prevPos[0]][prevPos[1]-1] == cmp or maps[prevPos[0]][prevPos[1]+1] == cmp and not slopeCheck:
        slopeCheck = True
      if cnt == L:
        slopeCheck = False
        cnt = 0
      cnt += 1
    cmp = maps[r][i]  
    prevPos = (r, i)
  return True


def checkRow(maps, c):
  cmp = maps[0][c]
  prevPos = (0, c)
  slopeCheck = False
  cnt = 0
  for i in range(1, N):
    if maps[i][c] == cmp: # 이전과 동일한 값이면 계속 진행
      continue
    if (maps[i][c] - cmp) > 1: # 높이의 차가 1이상이면 경사로를 깔아도 못지나간다.
      return False
    
    if slopeCheck and (maps[i][c] - cmp) != 1:
      return False

    # prevPos에서 왼쪽 행 or 오른 쪽행의 값이 (r, c)의 값과 같이야한다.
    if (maps[i][c] - cmp) == 1:
      left, right = prevPos[1]-1, prevPos[1]+1
      
      if maps[prevPos[0]][prevPos[1]-1] == cmp or maps[prevPos[0]][prevPos[1]+1] == cmp and not slopeCheck:
        slopeCheck = True
      if cnt == L:
        slopeCheck = False
        cnt = 0
      cnt += 1
    cmp = maps[i][c]  
    prevPos = (i, c)
  return True

def indexCheck(pos):
  if pos<0 and pos>n:
    return False
  return True

def solve():
  ans = 0
  for i in range(N):
    if checkColumn(maps, i):
      ans += 1
    if checkRow(maps, i):
      ans += 1
  return ans

print(solve())

