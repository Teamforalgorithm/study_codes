import sys
input = lambda: sys.stdin.readline().strip()

changes = 1000 - int(input())
cnt = 0
for i in [500, 100, 50, 10, 5, 1]:
  cnt += changes // i
  changes %= i

print(cnt)
