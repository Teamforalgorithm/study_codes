'''
BOJ - 2618
'''
import sys
input = lambda: sys.stdin.readline().strip()
dp = [[0]*2)*1001 for _ in range(1001)]

n = int(input()) # 도로의 개수
w = int(input()) # 사건의 개수

fir, sec = [], []
fir[0] = [1, 1]
sec[0] = [n, n]

pos = []
for _ in range(w):
  x, y = map(int, input().split())
  fir.append(x)
  pos.append([x, y])

print(pos)

def solve(c1, c2):
  if c1 == w or c2 == w:
    return 0
  ret = dp[c1][c2]
  if ret != -1:
    return ret
  
  np = max(c1, c2) + 1
  n1 = abs()


def backtracking(first, second):
  

print(solve(0,0))
# backtracking(0,0)



