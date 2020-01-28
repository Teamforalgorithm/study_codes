import sys
input = lambda: sys.stdin.readline().strip()

n, m = map(int, input().split())
arr = list(map(int, input().split()))
max_sub = []

for H in arr:
  sub = 0
  for val in arr:
    if val <= H:
      continue
    sub += val - H
  max_sub.append((sub, H))

height = [val for H, val in max_sub if H >= m]
print(max(height))

