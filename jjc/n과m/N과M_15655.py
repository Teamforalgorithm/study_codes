import sys

n,m = map(int, sys.stdin.readline().split())
arr = sorted(list(map(int, sys.stdin.readline().split())))
check = [False]*n
a = [0]*9
arr.sort()
def solve(arr, start, idx):
    if idx==m:
        print(' '.join(map(str, [i for i in a if i!=0])))
        return
    else:
        for i in range(start, n):
            a[idx] = arr[i]
            solve(arr, i+1, idx+1)

solve(arr,0,0)