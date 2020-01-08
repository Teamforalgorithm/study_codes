import sys
from itertools import combinations
input = sys.stdin.readline

loop = True

while loop:
  tmp = list(map(int, input().strip().split()))
  n = tmp[0]  
  arr = tmp[1:]
  if n==0:
    flag = False
    break

  for step in combinations(arr, 6):
    print(' '.join(map(str, step)))

  print('')