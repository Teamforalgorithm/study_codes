import sys

N, K = map(int, sys.stdin.readline().split())
arr = []
remnant = K
count = 0

for i in range(N):
    arr.append(int(sys.stdin.readline()))

for i in reversed(arr):
    while remnant >= i:
        remnant -= i
        count += 1
    if remnant == 0:
        break

print(count)
