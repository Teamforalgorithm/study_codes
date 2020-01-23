import sys

N, K = map(int, sys.stdin.readline().split())
types = []
count = 0

for i in range(N):
    types.append(int(sys.stdin.readline()))

i = len(types) - 1
while i >= 0:
    if K >= types[i]:
        K -= types[i]
        count += 1
        continue
    i -= 1

print(count)
