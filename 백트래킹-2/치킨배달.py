import sys
input = sys.stdin.readline

import itertools

N, M = map(int, input().split())
maps = []
ans = 99999
for _ in range(N):
  maps.append(list(map(int, input().split())))

# maps에서 치킨집(2)인 인덱스들의 배열을 구함
chicken = [(nx+1, ny+1) for nx, row in enumerate(maps) for ny, val in enumerate(row) if val == 2]
# maps에서 집(1)인 인덱스들의 배열을 구함
home = [(nx+1, ny+1) for nx, row in enumerate(maps) for ny, val in enumerate(row) if val == 1]


for left_chicken in itertools.combinations(chicken, M):
  tmp = 0
  for h_pos in home:
      chicken_distance = 99999
      for c_pos in left_chicken:
          distance = abs(h_pos[0] - c_pos[0]) + abs(h_pos[1] - c_pos[1])
          if distance < chicken_distance:
              chicken_distance = distance
      tmp += chicken_distance
  if tmp < ans:
      ans = tmp
print(ans)