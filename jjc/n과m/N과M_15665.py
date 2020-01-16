import sys

n, m = map(int, sys.stdin.readline().split())
arr = sorted(set(map(int, sys.stdin.readline().split())))

def solve(selected, idx):
    if idx==m:
        print(' '.join(map(str, selected)))
    else:
        if(idx==0):
            for n in arr:
                solve(selected+[n], idx+1)
        else:
            for n in arr:
                if n>=selected[-1]:
                    solve(selected+[n], idx+1)    

solve([], 0)