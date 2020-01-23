# WRONG
import sys

N, M = map(int, sys.stdin.readline().split())
arr = list(map(int, sys.stdin.readline().split()))

arr = list(reversed(sorted(arr)))

acquired = 0
count = 1

for i, j in zip(arr, arr[1:] + [0]):
    if (i - j) == 0:
        continue
    acquired += (i - j) * count
    if acquired >= M:
        print(j)
        break
    count += 1
