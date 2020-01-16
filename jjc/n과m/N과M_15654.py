import sys

n,m = map(int, sys.stdin.readline().split())
arr = sorted(list(map(int, sys.stdin.readline().split())))
check = [False]*n
a = []

def solve(arr, cnt):
    if cnt==m:
        print(" ".join(map(str, a)))
        return
    for i in range(n):
        if not check[i]:
            check[i] = True
            a.append(arr[i])
            solve(arr, cnt+1)
            a.pop()
            check[i] = False

solve(arr, 0)

