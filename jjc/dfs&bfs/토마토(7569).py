import sys
input = sys.stdin.readline
sys.setrecursionlimit(10**8)
# 상 하 좌 우 
# 앞 뒤?..
dx = [-1, 1, 0, 0]
dy = [0, 0, 1, -1]

m, n, h = map(int, input().split())
maps = []
for _ in range(n*h):
  maps.append(list(map(int, input().split())))
  

print(maps)