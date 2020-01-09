import sys
input = sys.stdin.readline

t = int(input())
ans = 0

d = [0, 1, 2, 4]
for i in range(4, 11):
  d.append(d[i-1] + d[i-2] + d[i-3])  

for _ in range(t):
  num = int(input())
  print(d[num])
  