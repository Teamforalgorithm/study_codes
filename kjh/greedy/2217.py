import sys

num = int(sys.stdin.readline())
arr = []

for i in range(num):
    arr.append(int(sys.stdin.readline()))

count = len(arr)
max_val = 0
for i in sorted(arr):
    if (i * count) > max_val:
        max_val = i * count
    count -= 1

print(max_val)
