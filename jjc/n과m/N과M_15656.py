import sys

n,m = map(int, sys.stdin.readline().split())
arr = sorted(list(map(int, sys.stdin.readline().split())))
check = [False]*n
a = [0]*9

def solve(arr, cnt):
    if cnt == m:
        print(' '.join(map(str, [i for i in a if i!= 0])))
        return
    else:
        for i in range(n):
            a.append(arr[i])
            solve(arr, cnt+1)
            a.pop()

solve(arr, 0)