import sys, math
input = lambda: sys.stdin.readline().strip()

direction = [(1, 0), (0, -1), (-1, 0), (0, 1)]
info = []
maps = [[-1] * 101 for _ in range(101)]
print(maps)
n = int(input())
for _ in range(n):
  info.append(list(map(int, input().split())))

def distance(pos1, pos2):
  sub1, sub2 = abs(pos1[0] - pos2[0]), abs(pos1[1] - pos2[1])
  return math.sqrt(sub1**2 + sub2**2)


def rotate(): # 끝점기준으로 시계방향 90도 돌리기
  
  print()



def curve():
  while info:
    x, y, d, g = info.pop(0)
    maps[x][y] += 1
    start = (x,y)
    end = 0
    for _ in range(g):
      if g==0:
        # 처음에만
        nx, ny = x+direction[d][0], y+direction[d][1]
        end = (nx, ny)
        maps[nx][ny] += 1
      else: # 1세대 이상부터
        end = max(end, distance(start, (nx, ny)))
        # rotate
        # position+1
  
  # 정사각형 개수
  





