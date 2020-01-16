import sys
num = int(sys.stdin.readline())
arr = sorted(list(map(int, sys.stdin.readline().split())))

print(int(arr[0]) * int(arr[-1]))
