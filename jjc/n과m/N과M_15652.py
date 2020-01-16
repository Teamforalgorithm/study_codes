import sys
n, m = map(int, sys.stdin.readline().split())
answer = [0]*9

def solve(start, idx):
    if idx == m:
        print(' '.join(map(str, [i for i in answer if i!=0])))
        return
    else:
        for i in range(start, n+1):
           answer[idx] = i
           solve(i, idx+1)

solve(1, 0)