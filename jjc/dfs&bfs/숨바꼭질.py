import sys
from collections import deque

input = sys.stdin.readline

# 걷게 되면 1초 후에 -1 또는 +1로 이동
# 순간이동을 하면 2*X위치

def bfs():
  que = deque()
  que.append(n)
  while que:
    x = que.popleft()
    if x == k:
      print(times[k])
      return
    for cur_x in [x-1, x+1, 2*x]:
      if 0 <= cur_x < 100001 and not times[cur_x]:
        times[cur_x] = times[x] + 1
        que.append(cur_x)

n, k = map(int, input().split())
times = [0]*100001
bfs()


