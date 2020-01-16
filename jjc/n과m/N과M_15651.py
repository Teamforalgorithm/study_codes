import sys
n, m = map(int, sys.stdin.readline().split())
answer = []

def solve(cnt):
    if cnt == m:
        print(' '.join(map(str, answer)))
        return
    else:
        for i in range(n):            
            answer.append(i+1)
            solve(cnt+1)
            answer.pop()

solve(0)