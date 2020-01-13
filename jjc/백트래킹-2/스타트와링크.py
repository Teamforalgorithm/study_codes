import sys
from itertools import combinations
input = sys.stdin.readline

n = int(input())
arr = []
ans = 9999999
for _ in range(n):
  arr.append(list(map(int, input().split())))

people = list(range(n))
comb = list(combinations(people, len(people)//2))

for cur in comb:
  rest = list(set(people) - set(cur))
  rest_sum, cur_sum = 0, 0
  cur_comb = list(combinations(cur, 2))
  rest_comb = list(combinations(rest, 2))

  for x, y in cur_comb:
    cur_sum += arr[x][y] + arr[y][x]

  for x, y in rest_comb:
    rest_sum += arr[x][y] + arr[y][x]
  
  ans = min(ans, abs(cur_sum - rest_sum))

print(ans)